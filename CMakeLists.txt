cmake_minimum_required (VERSION 2.6)
project(a2GoAT)

# check for in-source build, forbid it!
if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR AND NOT MSVC_IDE)
  message(FATAL_ERROR "\nIn-source build attempt detected!\n"
    "Please create a new directory (e.g. build) and run `cmake ..`.\n"
    "Also don't forget to delete the created CMakeCache.txt and CMakeFiles dir"
    )
endif()
    
include(cmake/settings.cmake)
include(cmake/doxygen.cmake)

message(STATUS "*** Build Type:      " ${CMAKE_BUILD_TYPE})
message(STATUS "*** Compiler Flags:  " ${DEFAULT_COMPILE_FLAGS})
message(STATUS "*** Install libs to: " ${LIBRARY_OUTPUT_PATH})
message(STATUS "*** Install bin to:  " ${EXECUTABLE_OUTPUT_PATH})

# require a fairly recent ROOT version
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(ROOT "5.30" REQUIRED)

# since all subprojects need ROOT, set that up here
include_directories(${ROOT_INCLUDES})
link_directories(${ROOT_LIBRARY_DIR})

include_directories(inc)


add_executable(MyGoAT
   inc/GTree.h
   inc/GTreeRawEvent.h
   inc/GTreeEvent.h
   inc/GTreeTagger.h
   inc/GTreeScaler.h
   inc/GTreeParticle.h
   inc/GTreeMeson.h
   inc/GTreeTrigger.h
   inc/GTreeFit.h
   inc/GTreeManager.h
   inc/GCorrectScalers.h
   inc/GParticleReconstruction.h
   inc/GMesonReconstruction.h
   inc/GSetMesonMass.h
   inc/GTaggerReconstruction.h
   inc/GProtonReconstruction.h
   inc/GKinFitterParticle.h
   inc/GKinFitter.h
   inc/GFitEtap6g.h
   inc/MyGoAT.h
   src/GTree.cc
   src/GTreeRawEvent.cc
   src/GTreeEvent.cc
   src/GTreeTagger.cc
   src/GTreeScaler.cc
   src/GTreeParticle.cc
   src/GTreeMeson.cc
   src/GTreeTrigger.cc
   src/GTreeFit.cc
   src/GTreeManager.cc
   src/GCorrectScalers.cc
   src/GParticleReconstruction.cc
   src/GMesonReconstruction.cc
   src/GSetMesonMass.cc
   src/GTaggerReconstruction.cc
   src/GProtonReconstruction.cc
   src/GKinFitterParticle.cc
   src/GKinFitter.cc
   src/GFitEtap6g.cc
   src/MyGoAT.cc
   )
target_link_libraries(MyGoAT ${ROOT_LIBRARIES})

add_executable(MyGoATPlot
   inc/GTree.h
   inc/GTreeRawEvent.h
   inc/GTreeEvent.h
   inc/GTreeTagger.h
   inc/GTreeScaler.h
   inc/GTreeParticle.h
   inc/GTreeMeson.h
   inc/GTreeTrigger.h
   inc/GTreeFit.h
   inc/GTreeManager.h
   inc/GPlotInvMass.h
   inc/GPlotTime.h
   inc/GPlotProton.h
   inc/GHist.h
   inc/GHistParticle.h
   inc/GHistTaggedParticle.h
   inc/GHistTaggedMeson.h
   inc/GHistHelTaggedMeson.h
   inc/GPlotCut.h
   inc/GPlot.h
   inc/GPlotPi0bins.h
   inc/GPlotPi0.h
   inc/GPlotEtabins.h
   inc/GPlotEta.h
   inc/GPlotCutMC.h
   inc/GPlotEnergyBins.h
   inc/GPlotScalers.h
   inc/MyGoAT.h
   src/GTree.cc
   src/GTreeRawEvent.cc
   src/GTreeEvent.cc
   src/GTreeTagger.cc
   src/GTreeScaler.cc
   src/GTreeParticle.cc
   src/GTreeMeson.cc
   src/GTreeTrigger.cc
   src/GTreeFit.cc
   src/GTreeManager.cc
   src/GPlotInvMass.cc
   src/GPlotTime.cc
   src/GPlotProton.cc
   src/GHist.cc
   src/GHistParticle.cc
   src/GHistTaggedParticle.cc
   src/GHistTaggedMeson.cc
   src/GHistHelTaggedMeson.cc
   src/GPlotCut.cc
   src/GPlot.cc
   src/GPlotPi0bins.cc
   src/GPlotPi0.cc
   src/GPlotEtabins.cc
   src/GPlotEta.cc
   src/GPlotCutMC.cc
   src/GPlotEnergyBins.cc
   src/GPlotScalers.cc
   src/MyGoATPlot.cc
   )
target_link_libraries(MyGoATPlot ${ROOT_LIBRARIES})

add_executable(MyGoATCut
   inc/GTree.h
   inc/GTreeRawEvent.h
   inc/GTreeEvent.h
   inc/GTreeTagger.h
   inc/GTreeScaler.h
   inc/GTreeParticle.h
   inc/GTreeMeson.h
   inc/GTreeTrigger.h
   inc/GTreeFit.h
   inc/GTreeManager.h
   inc/GRawCut.h
   inc/GCut.h
   inc/MyGoAT.h
   src/GTree.cc
   src/GTreeRawEvent.cc
   src/GTreeEvent.cc
   src/GTreeTagger.cc
   src/GTreeScaler.cc
   src/GTreeParticle.cc
   src/GTreeMeson.cc
   src/GTreeTrigger.cc
   src/GTreeFit.cc
   src/GTreeManager.cc
   src/GRawCut.cc
   src/GCut.cc
   src/MyGoATCut.cc
   )
target_link_libraries(MyGoATCut ${ROOT_LIBRARIES})
