#
cmake_minimum_required(VERSION 3.16...3.21)
project(firstSim)

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#
add_executable(sim sim.cc ${sources} ${headers})
target_link_libraries(sim ${Geant4_LIBRARIES})

#----------------------------------------------------------------------------
# Copy all scripts to the build directory, i.e. the directory in which we
# build B4d. This is so that we can run the executable directly because it
# relies on these scripts being in the current working directory.
#
set(SIM_SCRIPTS
  run.mac
  vis.mac
  run_ElectronUniLogISO.mac
  run_GammaUniLogISO.mac
  run_SrY90_ISO.mac
  run_Sb124_ISO.mac
  run_ElectronPowerLawISO.mac
  run_GammaPowerLawISO.mac
  run_GammaSelectedEnergiesISO.mac
  run_Cs137_disk.mac
  run_SrY90_disk.mac
  run_monoE_disk.mac
  run_ElectronUniLog_disk.mac
  run_beam.mac
  )

foreach(_script ${SIM_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS sim DESTINATION bin)

