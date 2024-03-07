#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "podofo_shared" for configuration "Debug"
set_property(TARGET podofo_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(podofo_shared PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/libpodofo.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "LibXml2::LibXml2"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/libpodofo.dll"
  )

list(APPEND _cmake_import_check_targets podofo_shared )
list(APPEND _cmake_import_check_files_for_podofo_shared "${_IMPORT_PREFIX}/lib/libpodofo.dll.a" "${_IMPORT_PREFIX}/bin/libpodofo.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
