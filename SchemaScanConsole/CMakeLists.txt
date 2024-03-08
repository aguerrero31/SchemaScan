project(SchemaScanConsole
        LANGUAGES C CXX
)

add_executable(${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/SchemaScanConsole.cpp
)

target_link_libraries(SchemaScanConsole
        PRIVATE
            SchemaScanLib
)