//
// Created by Andrew on 2/12/2024.
//

#include <podofo/podofo.h>
#include <memory>
#include <iostream>
#include "trunk/src/hashlibpp.h"
#include <filesystem>
#include <stdexcept>
#include "podofo/main/PdfInfo.h"

#ifndef SCHEMASEARCH_SCHEMATIC_H
#define SCHEMASEARCH_SCHEMATIC_H


class Schematic {
public:
    Schematic(const std::string &fpath);
    ~Schematic();
    // Functions
private:
    // Class Members
    std::string file_name_;
    std::string path_;
    int page_count_;
    std::string md5_hash_;
    std::vector<std::string> parsed_pages_;
    // Functions
    void setHash();
    void parsePages();
    void setInfo();
    void setFileName();
};


#endif //SCHEMASEARCH_SCHEMATIC_H
