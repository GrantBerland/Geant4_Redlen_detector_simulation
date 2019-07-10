# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# compile CXX with /usr/bin/c++
CXX_FLAGS =  -W -Wall -pedantic -Wno-non-virtual-dtor -Wno-long-long -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-variadic-macros -Wshadow -pipe -DG4USE_STD11 -pthread -ftls-model=initial-exec -std=c++11 -O3 -DNDEBUG -fno-trapping-math -ftree-vectorize -fno-math-errno   -std=c++11

CXX_DEFINES = -DG4INTY_USE_QT -DG4INTY_USE_XT -DG4MULTITHREADED -DG4UI_USE -DG4UI_USE_QT -DG4UI_USE_TCSH -DG4VERBOSE -DG4VIS_USE -DG4VIS_USE_OPENGL -DG4VIS_USE_OPENGLQT -DG4VIS_USE_OPENGLX -DG4_STORE_TRAJECTORY

CXX_INCLUDES = -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/analysis/g4tools/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/analysis/accumulables/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/analysis/csv/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/analysis/hntools/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/analysis/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/analysis/root/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/analysis/xml/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/digits_hits/detector/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/digits_hits/digits/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/digits_hits/hits/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/digits_hits/scorer/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/digits_hits/utils/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/error_propagation/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/event/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/externals/clhep/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/externals/zlib/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/geometry/biasing/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/geometry/divisions/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/geometry/magneticfield/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/geometry/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/geometry/navigation/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/geometry/solids/Boolean/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/geometry/solids/CSG/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/geometry/solids/specific/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/geometry/volumes/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/global/HEPGeometry/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/global/HEPNumerics/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/global/HEPRandom/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/global/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/graphics_reps/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/intercoms/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/interfaces/GAG/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/interfaces/basic/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/interfaces/common/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/materials/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/parameterisations/gflash/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/particles/adjoint/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/particles/bosons/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/particles/hadrons/barions/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/particles/hadrons/ions/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/particles/hadrons/mesons/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/particles/leptons/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/particles/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/particles/shortlived/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/particles/utils/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/persistency/ascii/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/persistency/gdml/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/persistency/mctruth/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/physics_lists/builders/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/physics_lists/constructors/decay/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/physics_lists/constructors/electromagnetic/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/physics_lists/constructors/factory/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/physics_lists/constructors/gamma_lepto_nuclear/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/physics_lists/constructors/hadron_elastic/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/physics_lists/constructors/hadron_inelastic/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/physics_lists/constructors/ions/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/physics_lists/constructors/limiters/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/physics_lists/constructors/stopping/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/physics_lists/lists/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/physics_lists/util/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/biasing/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/biasing/generic/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/biasing/importance/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/cuts/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/decay/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/adjoint/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/dna/processes/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/dna/models/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/dna/utils/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/dna/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/dna/molecules/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/dna/molecules/types/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/highenergy/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/lowenergy/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/muons/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/pii/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/polarisation/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/standard/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/utils/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/electromagnetic/xrays/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/cross_sections/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/abla/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/abrasion/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/binary_cascade/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/cascade/cascade/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/coherent_elastic/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/de_excitation/ablation/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/de_excitation/evaporation/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/de_excitation/fermi_breakup/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/de_excitation/fission/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/de_excitation/gem_evaporation/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/de_excitation/handler/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/de_excitation/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/de_excitation/multifragmentation/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/de_excitation/photon_evaporation/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/de_excitation/util/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/em_dissociation/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/fission/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/im_r_matrix/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/inclxx/utils/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/inclxx/incl_physics/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/inclxx/interface/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/gamma_nuclear/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/lend/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/lepto_nuclear/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/particle_hp/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/parton_string/diffraction/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/parton_string/hadronization/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/parton_string/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/parton_string/qgsm/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/pre_equilibrium/exciton_model/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/qmd/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/quasi_elastic/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/radioactive_decay/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/rpg/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/theo_high_energy/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/models/util/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/processes/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/stopping/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/hadronic/util/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/optical/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/solidstate/phonon/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/solidstate/channeling/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/parameterisation/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/scoring/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/processes/transportation/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/readout/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/run/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/track/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/tracking/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/visualization/FukuiRenderer/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/visualization/HepRep/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/visualization/RayTracer/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/visualization/Tree/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/visualization/VRML/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/visualization/XXX/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/visualization/externals/gl2ps/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/visualization/gMocren/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/visualization/management/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/visualization/modeling/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4.10.04.p02/source/visualization/OpenGL/include -isystem /usr/include/qt4 -isystem /usr/include/qt4/QtCore -isystem /usr/include/qt4/QtGui -isystem /usr/include/qt4/QtOpenGL -I/home/grant/Documents/Research/Marshall_Research/redlen_detector_scattering/include -isystem /home/grant/Documents/Research/Marshall_Research/geant4_build/source/externals/zlib 
