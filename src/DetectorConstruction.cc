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
// $Id: DetectorConstruction.cc 94307 2015-11-11 13:42:46Z gcosmo $
//
/// \file DetectorConstruction.cc
/// \brief Implementation of the DetectorConstruction class

#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4GenericPolycone.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4IntersectionSolid.hh"
#include "G4RotationMatrix.hh"
#include "G4SubtractionSolid.hh"

#include <fstream>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();

  // Envelope parameters
  //
  G4double env_sizeRadius = 20*cm;

    // Material: Vacuum
  G4Material* vacuum_material = new G4Material("Vacuum",
              1.0 , 1.01*g/mole, 1.0E-25*g/cm3,
              kStateGas, 2.73*kelvin, 3.0E-18*pascal );



  // CZT for detector
  G4Element* Cd = new G4Element("Cadmium","Cd",48., 112.41*g/mole);
  G4Element* Zn = new G4Element("Zinc","Zn", 30., 65.38*g/mole);
  G4Element* Te = new G4Element("Tellurium","Te", 52., 127.60*g/mole);
  G4Material* CZT = new G4Material("CZT", 5.8*g/cm3, 3);
  CZT->AddElement(Cd, 48*perCent);
  CZT->AddElement(Zn, 2*perCent);
  CZT->AddElement(Te, 50*perCent);

  G4Element* N  = new G4Element("Nitrogen", "N", 7, 14.01*g/mole);
  G4Element* O  = new G4Element("Oxygen",   "O", 8, 16.00*g/mole);
  

  // Air density in Boulder, CO
  G4int ncomponents; G4double fractionmass;
  G4Material* Air20 = new G4Material("Air", 1.056*kg/m3, ncomponents=2,
                      kStateGas, 293.*kelvin, 1.*atmosphere);
  
  Air20->AddElement(N, fractionmass=0.7);
  Air20->AddElement(O, fractionmass=0.3);


  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //
  // World
  //
  G4double world_sizeRadius = 1.2*env_sizeRadius;
  //G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

  G4Sphere* solidWorld = new G4Sphere("World",    //its name
       0., world_sizeRadius, 
       0.*deg, 360.*deg,
       0.*deg, 180.*deg);     //its size

  G4LogicalVolume* logicWorld =
    new G4LogicalVolume(solidWorld,          //its solid
                        vacuum_material,           //its material
                        "World");            //its name

  G4VPhysicalVolume* physWorld =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking

  //
  // Envelope
  //
  G4Sphere* solidEnv = new G4Sphere("Envelope",            //its name
        0., env_sizeRadius, 
	0.*deg, 360.*deg,
	0.*deg, 180.*deg); //its size

  G4LogicalVolume* logicEnv =
    new G4LogicalVolume(solidEnv,            //its solid
                        Air20,             //its material
                        "Envelope");         //its name

  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicEnv,                //its logical volume
                    "Envelope",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  // Shielding and Detector Construction
  //

  G4double outerBoxThickness = 3.0*cm/2.;
  G4double shieldThickness = 3.*mm;
  G4double fDetectorLength    = 40.*mm/2;
  G4double fDetectorThickness = 5.*mm/2;

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




  G4RotationMatrix* rotm = new G4RotationMatrix();

  G4SubtractionSolid*
  sShielding_pre = new G4SubtractionSolid("Shielding",
                                       sShieldingBox,
                                       sShieldingCutout);//,
                        //             rotm,
                        //            G4ThreeVector(0.,0.,0.)); 
  G4SubtractionSolid*
  sShielding = new G4SubtractionSolid("Shielding",
                                       sShielding_pre,
                                       sSlit,
                                       rotm,
                                      G4ThreeVector(2.5*cm,0.,0.));


  G4LogicalVolume* fLogicShielding = 
	  new G4LogicalVolume(sShielding,      //shape
                             nist->FindOrBuildMaterial("G4_Al"),//material
                             "Shielding");               //name


  new G4PVPlacement(0,
		    G4ThreeVector(),
		    fLogicShielding,
		    "Shielding",
		    logicEnv,
		    false, 
		    0);



  G4VSolid*
  sDetector = new G4Box("Detector",
                fDetectorThickness, fDetectorLength, fDetectorLength);


  G4LogicalVolume* fLogicDetector = 
	  new G4LogicalVolume(sDetector,       //shape
                             CZT,//material
                             "Detector");               //name


  new G4PVPlacement(0,
		  G4ThreeVector(),
		  fLogicDetector,
		  "Detector",
		  logicEnv,
		  false,
		  0);




  // always return the physical World
  return physWorld;
}






