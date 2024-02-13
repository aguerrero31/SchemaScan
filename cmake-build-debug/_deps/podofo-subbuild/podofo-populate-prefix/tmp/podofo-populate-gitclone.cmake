# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src/podofo-populate-stamp/podofo-populate-gitclone-lastrun.txt" AND EXISTS "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src/podofo-populate-stamp/podofo-populate-gitinfo.txt" AND
  "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src/podofo-populate-stamp/podofo-populate-gitclone-lastrun.txt" IS_NEWER_THAN "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src/podofo-populate-stamp/podofo-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src/podofo-populate-stamp/podofo-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: 'E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "C:/Program Files/Git/cmd/git.exe"
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/podofo/podofo.git" "podofo-src"
    WORKING_DIRECTORY "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/podofo/podofo.git'")
endif()

execute_process(
  COMMAND "C:/Program Files/Git/cmd/git.exe"
          checkout "02f43b71c1d4d2e791a9becd8ddd049d852fdf21" --
  WORKING_DIRECTORY "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '02f43b71c1d4d2e791a9becd8ddd049d852fdf21'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "C:/Program Files/Git/cmd/git.exe" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: 'E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src/podofo-populate-stamp/podofo-populate-gitinfo.txt" "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src/podofo-populate-stamp/podofo-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: 'E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src/podofo-populate-stamp/podofo-populate-gitclone-lastrun.txt'")
endif()
