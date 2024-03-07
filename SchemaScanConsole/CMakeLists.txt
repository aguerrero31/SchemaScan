add_executable(SchemaScanConsole SchemaScanConsole.cpp)

target_link_libraries(SchemaScanConsole
        PRIVATE
            SchemaScanLib
)