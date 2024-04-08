#include "Schematic.h"
#include "SchematicHandler.h"

#include <iostream>

int main(int argc, char* argv[]) {
    try {
        std::u32string path;
        std::cout << "Starting...\n\n";
        path = U"E:\\Electronics Repair\\Schematics & Boardviews";
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
        std::cout << "Found " << handler.getFoundFilesCount() << " schematic(s)\n";
        for (const auto &schematic : handler.getSchematics()) {
            std::cout << "Valid Schematic: " << SchemaUtils::u32StringToStdString(schematic->getFileName()) << "\n";
        }
        std::cout << "\n\n";
        for (const auto &schematic : handler.getSkippedSchematics()) {
            std::cout << "Skipped Schematic: " << SchemaUtils::u32StringToStdString(schematic) << "\n";
        }
        std::cout << "Scanned " << handler.getSchematicCount() << " schematic(s)\n";
        std::cout << "Skipped " << handler.getSkippedSchematicCount() << " schematic(s)\n";
    }
    catch (std::out_of_range &e) {
        std::cout << "Invalid: " << e.what() << "\n";
    }
}