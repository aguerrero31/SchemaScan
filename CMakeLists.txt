cmake_minimum_required(VERSION 3.27)
project(SchemaScan)

set(CMAKE_CXX_STANDARD 23)

## Set a default build type if none was specified
## Based on: https://github.com/openchemistry/tomviz/blob/master/cmake/BuildType.cmake
#set(DEFAULT_BUILD_TYPE "Release")
#if(EXISTS "${CMAKE_SOURCE_DIR}/.git")
#    set(DEFAULT_BUILD_TYPE "Debug")
#endif()
#if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
#    message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
#    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
#    # Set the possible values of build type for cmake-gui
#    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
#endif()
#
#if(WIN32) # Install dlls in the same directory as the executable on Windows
#    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
#    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
#endif()

add_subdirectory(SchemaScanLib)
add_subdirectory(SchemaScanConsole)
add_subdirectory(SchemaScanGUI)
add_subdirectory(deps/podofo-0.10.3)