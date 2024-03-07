# Install script for directory: E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/SchemaScan")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "E:/CLion2023/bin/mingw/bin/objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("E:/Programming/C++ Projects/SchemaScan/cmake-build-debug/deps/podofo-0.10.3/src/podofo/private/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo" TYPE FILE FILES "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/podofo.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/auxiliary" TYPE FILE FILES "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug/deps/podofo-0.10.3/src/podofo/podofo_config.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/main" TYPE FILE FILES
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfAcroForm.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfAction.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfAnnotation.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfAnnotationActionBase.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfAnnotationCollection.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfAnnotationWidget.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfAnnotation_Types.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfArray.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfButton.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfCIDToGIDMap.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfCMapEncoding.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfCanvas.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfCanvasInputDevice.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfCatalog.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfCharCodeMap.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfCheckBox.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfChoiceField.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfColor.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfComboBox.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfCommon.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfContentStreamOperators.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfContentStreamReader.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfContents.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfData.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfDataContainer.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfDataProvider.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfDate.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfDeclarations.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfDestination.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfDictionary.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfDifferenceEncoding.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfDocument.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfElement.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfEncoding.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfEncodingCommon.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfEncodingFactory.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfEncodingMap.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfEncodingMapFactory.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfEncodingShim.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfEncrypt.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfError.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfExtGState.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfExtension.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfField.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFieldChildrenCollection.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFileSpec.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFilter.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFont.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontCID.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontCIDTrueType.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontCIDType1.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontConfigWrapper.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontManager.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontMetrics.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontMetricsFreetype.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontMetricsObject.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontMetricsStandard14.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontObject.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontSimple.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontTrueType.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontTrueTypeSubset.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontType1.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfFontType3.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfGraphicsState.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfIdentityEncoding.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfImage.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfImmediateWriter.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfIndirectObjectList.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfInfo.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfListBox.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfMath.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfMemDocument.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfMemoryObjectStream.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfMetadata.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfName.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfNameTree.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfObject.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfObjectStream.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfObjectStreamParser.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfObjectStreamProvider.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfOperatorUtils.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfOutlines.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfPage.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfPageCollection.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfPainter.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfPainterPath.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfPainterTextObject.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfParser.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfParserObject.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfPostScriptTokenizer.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfPredefinedEncoding.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfPushButton.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfRadioButton.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfReference.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfResources.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfSignature.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfSigner.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfStatefulEncrypt.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfStreamedDocument.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfStreamedObjectStream.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfString.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfStringStream.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfTextBox.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfTextState.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfTokenizer.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfTrailer.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfVariant.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfVariantStack.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfWriter.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfXMPMetadata.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfXMPPacket.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfXObject.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfXObjectForm.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfXObjectPostScript.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfXRef.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfXRefEntry.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfXRefStream.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/main/PdfXRefStreamParserObject.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/auxiliary" TYPE FILE FILES
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/EnumFlags.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/InputDevice.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/InputStream.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/MathBase.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/Matrix.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/OutputDevice.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/OutputStream.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/Rect.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/StateStack.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/StreamDevice.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/StreamDeviceBase.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/Vector2.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/Version.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/basecompat.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/basedefs.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/baseincludes.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/basetypes.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/nullable.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/span.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/auxiliary/span.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/staging" TYPE FILE FILES
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/staging/PdfFunction.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/staging/PdfPainterExtensions.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/staging/PdfShadingPattern.h"
    "E:/Programming/C++ Projects/SchemaScan/deps/podofo-0.10.3/src/podofo/staging/PdfTilingPattern.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug/target/libpodofo.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug/target/libpodofo.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libpodofo.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libpodofo.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "E:/CLion2023/bin/mingw/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libpodofo.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/podofo/podofo-config.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/podofo/podofo-config.cmake"
         "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug/deps/podofo-0.10.3/src/podofo/CMakeFiles/Export/ea6d3232cf9813e3c405edafe67aa028/podofo-config.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/podofo/podofo-config-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/podofo/podofo-config.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/podofo" TYPE FILE FILES "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug/deps/podofo-0.10.3/src/podofo/CMakeFiles/Export/ea6d3232cf9813e3c405edafe67aa028/podofo-config.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/podofo" TYPE FILE FILES "E:/Programming/C++ Projects/SchemaScan/cmake-build-debug/deps/podofo-0.10.3/src/podofo/CMakeFiles/Export/ea6d3232cf9813e3c405edafe67aa028/podofo-config-debug.cmake")
  endif()
endif()

