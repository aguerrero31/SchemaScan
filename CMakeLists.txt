cmake_minimum_required(VERSION 3.26)
set(CMAKE_MESSAGE_LOG_LEVEL STATUS)
list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
)

project(SchemaScan
    LANGUAGES C CXX
    VERSION 0.0.1
)

include(vcpkg-init)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_DIRECTORY_LABELS ON)


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SchemaScanLib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SchemaScanConsole)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SchemaScanGUI)

add_dependencies(SchemaScanConsole SchemaScanLib)

include(cmake-utils)
