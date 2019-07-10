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
// $Id: SteppingAction.cc 74483 2013-10-09 13:37:06Z gcosmo $
//
/// \file SteppingAction.cc
/// \brief Implementation of the SteppingAction class

#include "SteppingAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"
// #include "DetectorAnalysis.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"

#include "G4AutoLock.hh"
#include <fstream>
#include <string>


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(EventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* step)
{
  G4bool isInDetector, isEnteringDetector;

  G4Track* track = step->GetTrack();
  const G4StepPoint* postPoint = step->GetPostStepPoint();

  G4String volName;
  G4String nextVolName;

  if(track->GetVolume()) {volName = track->GetVolume()->GetName();}
  if (track->GetNextVolume()) {nextVolName = track->GetNextVolume()->GetName();}

  G4bool check1 = (volName == "Detector");
  G4bool check2 = (nextVolName == "Detector");

  isInDetector = (check1 && check2);
  isEnteringDetector = (!check1 && check2);

  // Detector 1 particles
  if (isInDetector){

    // Lock thread during hit event and writing,
    // auto unlocks on step outside scope
    G4Mutex aMutex = G4MUTEX_INITIALIZER;
    G4AutoLock l(&aMutex);

    //G4ThreeVector pos = postPoint->GetPosition();
    G4double ene = (step->GetPreStepPoint()->GetKineticEnergy())
	         - (postPoint->GetKineticEnergy());
    
    std::ofstream hitFile_detector1;

    G4String fullFileName = "../data/hits.csv";

    hitFile_detector1.open(fullFileName, std::ios_base::app);
    hitFile_detector1 << ene/keV << "\n";
    hitFile_detector1.close();
  }

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
