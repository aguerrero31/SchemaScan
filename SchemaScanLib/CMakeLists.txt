add_library(SchemaScanLib "")

target_sources(SchemaScanLib
        PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/Schematic.cpp
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/Schematic.h
)

target_include_directories(SchemaScanLib
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
            ${PROJECT_SOURCE_DIR}/deps/hashlib2plus/trunk/src hashlib2plus
            ${PROJECT_SOURCE_DIR}/deps/podofo-0.10.3/src
)

target_link_libraries(SchemaScanLib PUBLIC hashlib2plus podofo)