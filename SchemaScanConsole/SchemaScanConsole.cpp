#include "Schematic.h"
#include "SchematicHandler.h"

#include <iostream>

int main(int argc, char* argv[]) {
    try {
        std::wstring path;
        std::cout << "Starting...\n";
        path = SchemaUtils::stringToWString(R"(E:Electronics Repair\Schematics & BoardViews\LOTS OF SCHEMATICS AND BOARDVIEWS bv_varios_repromod\BoardView Varios feat. REPROMOD\GPU Boardviews\NVIDIA)");
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
    }
    catch (std::out_of_range &e) {
        std::cout << "Invalid: " << e.what() << "\n";
    }
}