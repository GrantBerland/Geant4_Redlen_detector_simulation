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
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

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
  G4double env_sizeXY = 20*cm, env_sizeZ = 30*cm;

    // Material: Vacuum
    //TODO: check pressures, environment for Van Allen belt altitudes
  G4Material* vacuum_material = new G4Material("Vacuum",
              1.0 , 1.01*g/mole, 1.0E-25*g/cm3,
              kStateGas, 2.73*kelvin, 3.0E-18*pascal );

  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //
  // World
  //
  G4double world_sizeXY = 1.2*env_sizeXY;
  G4double world_sizeZ  = 1.2*env_sizeZ;
  // G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

  G4Box* solidWorld =
    new G4Box("World",                       //its name
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size

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
  G4Box* solidEnv =
    new G4Box("Envelope",                    //its name
        0.5*env_sizeXY, 0.5*env_sizeXY, 0.5*env_sizeZ); //its size

  G4LogicalVolume* logicEnv =
    new G4LogicalVolume(solidEnv,            //its solid
                        vacuum_material,             //its material
                        "Envelope");         //its name

  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicEnv,                //its logical volume
                    "Envelope",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking



  std::fstream configFile;
  configFile.open("../src/detector_config.txt", std::ios_base::in);

  // Initialize variables to store detector dimensions
  G4double det1_t_um, det2_t_um, dist_bw_det_mm, window_t_um, window_gap_mm;

  // Load detector dimensions into variables
  configFile >> det1_t_um >> det2_t_um >>
              dist_bw_det_mm >> window_t_um >> window_gap_mm;

  configFile.close();

  // Dimensions for detectors (detector 1 and 2 use the same planar dimensions)
  G4double detector_dimX = 5.*cm;
  G4double detector_dimZ = 5.*cm;
  G4double detector1_thickness = det1_t_um*um;
  G4double detector2_thickness = det2_t_um*um;

  G4double distance_between_detectors = dist_bw_det_mm*mm;

  // Window dimensions
  G4double window_thickness = window_t_um*um;
  G4double window_height    = 5.*cm;  // square window with this side dimension
  G4double window_gap       = window_gap_mm*mm;

  // ----------------------------------------------------------------
  // Materials for the detectors
  // ----------------------------------------------------------------

  // (Element name, symbol, atomic number, atomic mass) (as floats)
  G4Element* Si = new G4Element("Silicon","Si", 14., 28.0855*g/mole); // main wafer material for detector
  //G4Element* S = new G4Element("Sulfer","S", 16., 32.065*g/mole);   // possible doping material
  G4Element* B = new G4Element("Boron","B", 5., 10.811*g/mole);   // possible doping material

  //G4Element* Ga = new G4Element("Gallium","Ga", 31., 69.723*g/mole);
  //G4Element* As = new G4Element("Arsenic","As", 33., 74.9216*g/mole);
  //G4Element* Be = new G4Element("Beryllium","Be", 4., 9.0122*g/mole);   // material for window

  // Final doped silicon material to be used in the electron detector
  G4Material* DopedSilicon = new G4Material("DopedSilicon", 5.8*g/cm3, 2); // last argument is number of components in material
  DopedSilicon->AddElement(Si, 99.9*perCent);
  DopedSilicon->AddElement(B, 0.1*perCent);

  //DopedSilicon->AddElement(Ga, 2*perCent);  // Gallium
  //DopedSilicon->AddElement(As, 2*perCent);  // Arsenic (Gallium Arsenide)


  G4ThreeVector detector1_pos  = G4ThreeVector(0, 0, 0);
  G4ThreeVector detector2_pos = G4ThreeVector(0, 0, 0);


  G4VSolid* detector1_solid = new G4Box("detector",
                   detector_dimX, detector1_thickness, detector_dimZ);

  G4VSolid* detector2_solid = new G4Box("detector",
                  detector_dimX, detector2_thickness, detector_dimZ);

  // ----------------------------------------------------------------
  // Detector 1 (closest to window)
  // ----------------------------------------------------------------

  // Detector 1 exists at the origin
  detector1_pos  = G4ThreeVector(0, 0, 0);

  G4LogicalVolume* detector1 =
  new G4LogicalVolume(detector1_solid,      //its solid
                      DopedSilicon,        //its material
                      "detector1");      //its name

  new G4PVPlacement(0,                     //no rotation
                  detector1_pos,            //at position
                  detector1,                //its logical volume
                  "detector1",           //its name
                  logicEnv,                //its mother  volume
                  false,                   //no boolean operation
                  0,                       //copy number
                  checkOverlaps);          //overlaps checking

  // ----------------------------------------------------------------
  // Detector 2 (furthest from window)
  // ----------------------------------------------------------------

  detector2_pos  = G4ThreeVector(0, detector1_thickness/2 + detector2_thickness/2 + distance_between_detectors, 0);

  G4LogicalVolume* detector2 =
  new G4LogicalVolume(detector2_solid,      //its solid
                      DopedSilicon,        //its material
                      "detector2");      //its name

  new G4PVPlacement(0,                     //no rotation
                  detector2_pos,            //at position
                  detector2,                //its logical volume
                  "detector2",           //its name
                  logicEnv,                //its mother  volume
                  false,                   //no boolean operation
                  0,                       //copy number
                  checkOverlaps);          //overlaps checking


  // ----------------------------------------------------------------
  // Window
  // ----------------------------------------------------------------

  G4Material* window_material = nist->FindOrBuildMaterial("G4_Al");
  G4VSolid*   window_solid = new G4Box("window", detector_dimX, window_thickness,  window_height);

  G4ThreeVector window_pos;


  // Creation of beryllium window to repel protons and other particles

  window_pos = G4ThreeVector(0, -(detector1_thickness/2 + window_thickness/2 + window_gap),  0);

  G4LogicalVolume* window =
  new G4LogicalVolume(window_solid,         // its solid
                      window_material,      // its material
                      "window");    // its name

  new G4PVPlacement(0,                       //no rotation
                    window_pos,              //at position
                    window,                  //its logical volume
                    "window",       //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


  // always return the physical World
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
