# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-src"
  "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-build"
  "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix"
  "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/tmp"
  "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src/podofo-populate-stamp"
  "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src"
  "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src/podofo-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src/podofo-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/Programming/C++ Projects/SchemaSearch/cmake-build-debug/_deps/podofo-subbuild/podofo-populate-prefix/src/podofo-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
