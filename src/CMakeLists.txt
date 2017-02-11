cmake_minimum_required(VERSION 3.3.0 FATAL_ERROR)

######################
## Project Settings ##
######################

project(DVCppUtils CXX C)

set(DVCppUtils_VERSION_MAJOR "0")
set(DVCppUtils_VERSION_MINOR "0")
set(DVCppUtils_VERSION_PATCH "1")
set(DVCppUtils_VERSION
    "${DVCppUtils_MAJOR_VERSION}.${DVCppUtils_MINOR_VERSION}.${DVCppUtils_BUILD_VERSION}")

###################
## CMake Modules ##
###################

set(DVCppUtils_CMAKE_DIR ${DVCppUtils_SOURCE_DIR}/CMake)
set(CMAKE_MODULE_PATH ${DVCppUtils_CMAKE_DIR} ${CMAKE_MODULE_PATH})

include(DVInitializeBuildType)
include(DVPreventInSourceBuilds)
include(DVPreventInBuildInstalls)

#############
## Options ##
#############

option(BUILD_SHARED_LIBS "Build DVCppUtils with shared libraries." OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (NOT CMAKE_CXX_FLAGS)
  set(CMAKE_CXX_FLAGS "-Wall -Wextra" CACHE STRING "CXX Flags" FORCE)
endif()

option(BUILD_TESTING "Build the testing tree." OFF)

###################
## Bring in Code ##
###################

# Bring the headers into the project
include_directories("include")

# Add the sources
file(GLOB SOURCES "src/*.cxx")

# Generate the shared library from the sources
add_library(DVCppUtils ${SOURCES})

## Set the location for library installation
## Use "sudo make install" to apply
#install(TARGETS DVCppUtils DESTINATION "lib")
#
## Set the location for the header installation
## Use "sudo make install" to apply
#install(TARGETS ${HEADERS} DESTINATION "include")

#############
## Testing ##
#############

include(CTest)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()

