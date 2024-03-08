cmake_minimum_required(VERSION 3.27)

set(PODOFO_BUILD_LIB_ONLY ON)
find_package(podofo CONFIG REQUIRED)

project(SchemaScanLib
        LANGUAGES C CXX
        VERSION 0.0.1
)

file(GLOB
    hashlib2plus_sources
        "${CMAKE_CURRENT_SOURCE_DIR}/deps/hashlib2plus/src/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/deps/hashlib2plus/src/*.cpp"
)

add_library(${PROJECT_NAME} STATIC
    "${CMAKE_CURRENT_SOURCE_DIR}/Schematic.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Schematic.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SchemaScanLib.h"
    "${hashlib2plus_sources}"
)

if (NOT MSVC)
    target_compile_options(${PROJECT_NAME}
        PUBLIC
            -Wno-deprecated
    )
endif()

target_include_directories(${PROJECT_NAME}
    SYSTEM PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/hashlib2plus/src
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC $<IF:$<TARGET_EXISTS:podofo_shared>,podofo_shared,podofo_static>
)
