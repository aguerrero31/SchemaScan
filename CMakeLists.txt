cmake_minimum_required(VERSION 3.27)
project(SchemaScan)

set(CMAKE_CXX_STANDARD 23)

add_executable(SchemaScan SchemaScanConsole/SchemaScanConsole.cpp
        SchemaScanLib/Schematic.h
        SchemaScanLib/Schematic.cpp
        SchemaScanLib/SchemaScanLib.h)

# External Dependencies
find_package(podofo CONFIG REQUIRED)
add_subdirectory(deps/hashlib2plus)
target_link_libraries(SchemaScan PRIVATE $<IF:$<TARGET_EXISTS:podofo_shared>,podofo_shared,podofo_static> hashlib2plus SchemaScanLib)
target_include_directories(SchemaScan PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/deps/hashlib2plus" "${PROJECT_SOURCE_DIR}/SchemaScanLib")
set_target_properties(hashlib2plus PROPERTIES LINKER_LANGUAGE CXX)