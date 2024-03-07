if(NOT EXISTS "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug-event-trace/deps/podofo-0.10.3/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: \"E:/Programming/C++ Projects/SchemaScan/cmake-build-debug-event-trace/deps/podofo-0.10.3/install_manifest.txt\"")
endif(NOT EXISTS "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug-event-trace/deps/podofo-0.10.3/install_manifest.txt")

file(READ "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug-event-trace/deps/podofo-0.10.3/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach(file ${files})
  message(STATUS "Uninstalling \"${file}\"")
  if(NOT EXISTS "${file}")
    message(FATAL_ERROR "File \"${file}\" does not exists.")
  endif(NOT EXISTS "${file}")
  exec_program("E:/CLion2023/bin/cmake/win/x64/bin/cmake.exe" ARGS "-E remove \"${file}\""
    OUTPUT_VARIABLE rm_out
    RETURN_VARIABLE rm_retval)
  if("${rm_retval}" GREATER 0)
    message(FATAL_ERROR "Problem when removing \"${file}\"")
  endif("${rm_retval}" GREATER 0)
endforeach(file)
