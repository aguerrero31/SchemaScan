#include "Schematic.h"

#include <iostream>

int main(int argc, char* argv[]) {
    try {
        std::string path;
        std::cout << "Starting...\n";
        path = R"(E:\Electronics Repair\Schematics & BoardViews\MSI V3XX Schematics\V301\V301_11(00017967)_Decrypt.pdf)";
        //  std::cout << "Please enter the full path to the schematic: \n";
        // std::cin >> path;
        Schematic schematic(path);
        std::cout << "Parsing " << schematic.getFileName() << "\n";
        std::cout << "----------------------------------------\n";
        std::cout << "MD5 Hash: " << schematic.getMD5() << "\n";
        std::cout << "Pages found: " << schematic.getPageCount() << "\n";
        for (int i = 1; i <= schematic.getPageCount(); ++i) {
            std::cout << "Page " << i << ": \n";
            std::cout << schematic.getParsedPage(i) << "\n";
        }
        std::cout << "Parsing complete!";
    }
    catch (std::out_of_range &e) {
        std::cout << "Invalid, please try again" << "\n";
    }
}