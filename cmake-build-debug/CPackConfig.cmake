# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "E:/Programming/C++ Projects/SchemaScan;E:/Programming/C++ Projects/SchemaScan/cmake-build-debug")
set(CPACK_CMAKE_GENERATOR "Ninja")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "E:/CLion2023/bin/cmake/win/x64/share/cmake-3.27/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "SchemaScan built using CMake")
set(CPACK_GENERATOR "WIX")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALL_CMAKE_PROJECTS "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug;SchemaScan;ALL;/")
set(CPACK_INSTALL_PREFIX "C:/Program Files (x86)/SchemaScan")
set(CPACK_MODULE_PATH "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/cmake/modules;E:/Programming/C++ Projects/SchemaScan/cmake-build-debug/deps/podofo-0.10.3")
set(CPACK_NSIS_DISPLAY_NAME "SchemaScan 0.10.3")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
set(CPACK_NSIS_PACKAGE_NAME "SchemaScan 0.10.3")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJCOPY_EXECUTABLE "E:/CLion2023/bin/mingw/bin/objcopy.exe")
set(CPACK_OBJDUMP_EXECUTABLE "E:/CLion2023/bin/mingw/bin/objdump.exe")
set(CPACK_OUTPUT_CONFIG_FILE "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug/CPackConfig.cmake")
set(CPACK_PACKAGE_CONTACT "ceztko@gmail.com")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION "A C++ PDF manipulation library")
set(CPACK_PACKAGE_DESCRIPTION_FILE "E:/CLion2023/bin/cmake/win/x64/share/cmake-3.27/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "SchemaScan built using CMake")
set(CPACK_PACKAGE_FILE_NAME "SchemaScan-0.10.3-win64")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/podofo/podofo")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "SchemaScan 0.10.3")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "SchemaScan 0.10.3")
set(CPACK_PACKAGE_NAME "SchemaScan")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Francesco Pretto")
set(CPACK_PACKAGE_VERSION "0.10.3")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_READELF_EXECUTABLE "E:/CLion2023/bin/mingw/bin/readelf.exe")
set(CPACK_RESOURCE_FILE_LICENSE "E:/CLion2023/bin/cmake/win/x64/share/cmake-3.27/Templates/CPack.GenericLicense.txt")
set(CPACK_RESOURCE_FILE_README "E:/CLion2023/bin/cmake/win/x64/share/cmake-3.27/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "E:/CLion2023/bin/cmake/win/x64/share/cmake-3.27/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_7Z "ON")
set(CPACK_SOURCE_GENERATOR "7Z;ZIP")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug/CPackSourceConfig.cmake")
set(CPACK_SOURCE_ZIP "ON")
set(CPACK_SYSTEM_NAME "win64")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "win64")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
