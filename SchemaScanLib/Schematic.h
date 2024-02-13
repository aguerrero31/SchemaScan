//
// Created by Andrew on 2/12/2024.
//

#include <podofo/podofo.h>
#include <memory>
#include <iostream>
#include <filesystem>
#include <stdexcept>
#include "trunk/src/hashlibpp.h"
#include "podofo/main/PdfInfo.h"

#ifndef SCHEMASEARCH_SCHEMATIC_H
#define SCHEMASEARCH_SCHEMATIC_H


class Schematic {
public:
    Schematic(const std::string &fpath);
    ~Schematic();
    // Functions
    std::string getFileName() const;
    std::string getFilePath() const;
    unsigned int getPagecount() const;
    std::string getMD5() const;
    std::vector<std::string> getParsedPages() const;
    std::string getParsedPage(unsigned int page) const;
private:
    // Class Members
    std::string file_name_;
    std::string path_;
    unsigned int page_count_;
    std::string md5_hash_;
    std::vector<std::string> parsed_pages_;
    // Functions
    void setHash();
    void parsePages();
    void setInfo();
    void setFileName();
};


#endif //SCHEMASEARCH_SCHEMATIC_H
