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
/// \file DetectorConstruction.cc
/// \brief Implementation of the DetectorConstruction class
//
// $Id: DetectorConstruction.cc 70755 2013-06-05 12:17:48Z ihrivnac $
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"

#include "G4Tubs.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4RunManager.hh"
#include "G4IntersectionSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4RotationMatrix.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
:G4VUserDetectorConstruction(),
 fShieldingMater(0), fLogicShielding(0),	
 fDetectorMater(0), fLogicDetector(0),
 fWorldMater(0), fPhysiWorld(0),
 fDetectorMessenger(0) 
{
  fDetectorLength    = 39.*mm/2; 
  fDetectorThickness = 2.5*cm/2;
  
  fWorldLength = 10.*cm;
  fWorldRadius = fDetectorThickness + 10.*cm;
      
  DefineMaterials();
    
  fDetectorMessenger = new DetectorMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{ delete fDetectorMessenger;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  return ConstructVolumes();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::DefineMaterials()
{
  // build materials
 
  // CZT for detector
  G4Element* Cd = new G4Element("Cadmium","Cd",48., 112.41*g/mole);
  G4Element* Zn = new G4Element("Zinc","Zn", 30., 65.38*g/mole);
  G4Element* Te = new G4Element("Tellurium","Te", 52., 127.60*g/mole);
  G4Material* CZT = new G4Material("CZT", 5.8*g/cm3, 3);
  CZT->AddElement(Cd, 48*perCent);
  CZT->AddElement(Zn, 2*perCent);
  CZT->AddElement(Te, 50*perCent);

  fDetectorMater = CZT; 

  G4Element* N  = new G4Element("Nitrogen", "N", 7, 14.01*g/mole);
  G4Element* O  = new G4Element("Oxygen",   "O", 8, 16.00*g/mole);
  //
  G4int ncomponents; G4double fractionmass;      
  G4Material* Air20 = new G4Material("Air", 1.205*mg/cm3, ncomponents=2,
                      kStateGas, 293.*kelvin, 1.*atmosphere);
    Air20->AddElement(N, fractionmass=0.7);
    Air20->AddElement(O, fractionmass=0.3);
  
  // or use G4 materials data base
  //
  G4NistManager* man = G4NistManager::Instance(); 
 
  fWorldMater = Air20;

  fShieldingMater = man->FindOrBuildMaterial("G4_Al");

 ///G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::ConstructVolumes()
{
  
  // World
  //
  // (re) compute World dimensions if necessary
  fWorldLength = 10.*cm;
    
  G4VSolid*
  sWorld = new G4Box("World",                                 //name
                 fWorldLength, fWorldLength, fWorldLength); //dimensions  
                   
  G4LogicalVolume*
  lWorld = new G4LogicalVolume(sWorld,                  //shape
                             fWorldMater,               //material
                             "World");                  //name

  fPhysiWorld = new G4PVPlacement(0,                    //no rotation
                            G4ThreeVector(),            //at (0,0,0)
                            lWorld,                     //logical volume
                            "World",                    //name
                            0,                          //mother volume
                            false,                 //no boolean operation
                            0);                         //copy number
                            
  // Shielding Cutout
  //
  
  G4double outerBoxThickness = 1.0*cm;
  G4double shieldThickness = 3.*mm/2.;
  
  G4VSolid* sShieldingCutout = 
	  new G4Box("Shielding-cutout",
		    outerBoxThickness-shieldThickness,
		    fDetectorLength+outerBoxThickness-shieldThickness,
		    fDetectorLength+outerBoxThickness-shieldThickness);

  G4VSolid* sShieldingBox = 
	  new G4Box("Shielding-box",
		    outerBoxThickness,
		    fDetectorLength+outerBoxThickness,
		    fDetectorLength+outerBoxThickness);

  G4VSolid* sSlit = new G4Box("Slit", outerBoxThickness,
		  		      2.*mm/2.,
				      fDetectorLength);

  // Shielding
  //
  G4RotationMatrix* rotm = new G4RotationMatrix();

  G4SubtractionSolid* 
  sShielding_pre = new G4SubtractionSolid("Shielding", 
		                       sShieldingBox,
				       sShieldingCutout);//,
			//	       rotm,
			//	      G4ThreeVector(0.,0.,0.)); 
  G4SubtractionSolid* 
  sShielding = new G4SubtractionSolid("Shielding", 
		                       sShielding_pre,
				       sSlit,
				       rotm,
				      G4ThreeVector(2.5*cm,0.,0.)); 


  fLogicShielding = new G4LogicalVolume(sShielding,      //shape
                             fShieldingMater,            //material
                             "Shielding");               //name

           new G4PVPlacement(0,                         //no rotation
                           G4ThreeVector(),             //at (0,0,0)
                           fLogicShielding,              //logical volume
                           "Shielding",                  //name
                           lWorld,                   //mother  volume
                           false,                  //no boolean operation
                           0);                          //copy number
  // Detector
  //
  G4VSolid* 
  sDetector = new G4Box("Detector",  
                fDetectorThickness, fDetectorLength, fDetectorLength);


  fLogicDetector = new G4LogicalVolume(sDetector,       //shape
                             fDetectorMater,            //material
                             "Detector");               //name
                               
           new G4PVPlacement(0,                         //no rotation
                           G4ThreeVector(),             //at (0,0,0)
                           fLogicDetector,              //logical volume
                           "Detector",                  //name
                           fLogicShielding,            //mother  volume
                           false,                  //no boolean operation
                           0);                          //copy number


  
  //always return the root volume
  //
  return fPhysiWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
