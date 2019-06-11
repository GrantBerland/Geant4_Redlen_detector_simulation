//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file SteppingAction.cc
/// \brief Implementation of the SteppingAction class
//
// $Id: SteppingAction.cc 71404 2013-06-14 16:56:38Z maire $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "SteppingAction.hh"

#include "DetectorConstruction.hh"
#include "Run.hh"
#include "EventAction.hh"
#include "HistoManager.hh"

#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4AutoLock.hh"
#include "G4ThreeVector.hh"

#include <fstream>


namespace { G4Mutex myParticleLog = G4MUTEX_INITIALIZER; }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(DetectorConstruction* det, EventAction* event)
: G4UserSteppingAction(), fDetector(det), fEventAction(event),
  fileName("../data/hits.csv")
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
  Run* run = static_cast<Run*>(
        G4RunManager::GetRunManager()->GetNonConstCurrentRun());    
  
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

  //which volume ?
  //
  G4LogicalVolume* lVolume = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

  G4int iVol = 0;
  if (lVolume == fDetector->GetLogicTarget())   iVol = 1;
  if (lVolume == fDetector->GetLogicDetector()) iVol = 2;

  // count processes
  // 
  const G4StepPoint* endPoint = aStep->GetPostStepPoint();
  const G4VProcess* process   = endPoint->GetProcessDefinedStep();
  run->CountProcesses(process, iVol);
  
  // energy deposit
  //
  G4double edepStep = aStep->GetTotalEnergyDeposit();
  if (edepStep <= 0.) return;
  G4double time   = aStep->GetPreStepPoint()->GetGlobalTime();
  G4double weight = aStep->GetPreStepPoint()->GetWeight();   
  fEventAction->AddEdep(iVol, edepStep, time, weight);
  
  //fill ntuple id = 2
  G4int id = 2;   
  analysisManager->FillNtupleDColumn(id,0, edepStep);
  analysisManager->FillNtupleDColumn(id,1, time/s);
  analysisManager->FillNtupleDColumn(id,2, weight);
  analysisManager->AddNtupleRow(id);      

  // "Manual" recording method

  G4bool isEnteringDetector;
  G4String volName, nextVolName;

  G4Track* track = aStep->GetTrack();
  const G4StepPoint* postPoint = aStep->GetPostStepPoint();
  if (track->GetVolume()) {volName = track->GetVolume()->GetName();}
  if (track->GetNextVolume()) {nextVolName = track->GetNextVolume()->GetName();}

  isEnteringDetector = (volName != "Detector" && nextVolName == "Detector");
  std::cout << volName << " , " << nextVolName << std::endl; 
  if (isEnteringDetector){
    std::cout << "A hit!" << std::endl;
    G4double pos = postPoint->GetPosition();
    G4double ene = postPoint->GetKineticEnergy();
  
    LogParticle(pos, ene, fileName);
  }

}


void SteppingAction::LogParticle(G4ThreeVector pos, G4double ene, G4String
 detectorFileName)
{

    G4AutoLock lock(&myParticleLog);

    std::ofstream hitFile_detector;
    hitFile_detector.open(detectorFileName, std::ios_base::app);

    hitFile_detector << ene/keV << "\n";

    hitFile_detector.close();
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
