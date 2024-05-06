#include "Schematic.h"
#include "SchematicHandler.h"

#include <iostream>

int wmain(int argc, wchar_t* argv[]) {
    try {
        std::wstring path;
        std::cout << "Starting...\n\n";
        path = L"E:\\Electronics Repair\\Schematic Program Test\\smalltest";
        //  std::cout << "Please enter the full path to the schematic: \n";
        // std::cin >> path;
//        Schematic schematic(path);
//        std::cout << "Parsing " << schematic.getFileName() << "\n";
//        std::cout << "----------------------------------------\n";
//        std::cout << "MD5 Hash: " << schematic.getMD5() << "\n";
//        std::cout << "Pages found: " << schematic.getPageCount() << "\n";
//        for (int i = 1; i <= schematic.getPageCount(); ++i) {
//            std::cout << "Page " << i << ": \n";
//            std::cout << schematic.getParsedPage(i) << "\n\n";
//        }
//        std::cout << "Parsing complete!";
        SchematicHandler handler(path);
        // Parsing testing
        std::cout << "Found " << handler.getFoundFilesCount() << " schematic(s)\n";
        for (const auto &schematic : handler.getSchematics()) {
            std::wcout << "Valid Schematic: " << schematic->getFileName() << "\n";
        }
        std::cout << "\n\n";
        for (const auto &schematic : handler.getSkippedSchematics()) {
            std::wcout << "Skipped Schematic: " << schematic << "\n";
        }
        std::cout << "Scanned " << handler.getSchematicCount() << " schematic(s)\n";
        std::cout << "Skipped " << handler.getSkippedSchematicCount() << " schematic(s)\n";

        // Cache testing
        // std::wstring winCachePath = U"E:\\Electronics Repair\\Schematic Program Test\\cache\\";
        handler.cacheAll(true);
    }
    catch (std::out_of_range &e) {
        std::cout << "Invalid: " << e.what() << "\n";
    }
}