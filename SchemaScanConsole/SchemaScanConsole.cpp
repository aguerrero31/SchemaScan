#include <iostream>
#include "SchemaScanLib.h"

int main(int argc, char* argv[]) {
    try {
        Schematic schematic(argv[0]);
        std::cout << "Parsing "
    }
    catch (std::out_of_range &e) {
        std::cout << "Invalid, please try again" << "\n";
    }
}