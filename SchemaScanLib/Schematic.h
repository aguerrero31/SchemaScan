//
// Created by Andrew on 2/12/2024.
//

#pragma once

#include <memory>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include <podofo/podofo.h>
#include <hashlibpp.h>

#include "utils/SchemaUtils.h"

class Schematic {
public:
    Schematic(const std::u32string &fpath);
    ~Schematic(){};
    // Functions
    std::map<std::string, std::vector<int>> Search(const std::string &searchTerm, bool includePath) const;
    [[nodiscard]] std::u32string getFileName() const;
    [[nodiscard]] std::u32string getFilePath() const;
    [[nodiscard]] unsigned int getPageCount() const;
    [[nodiscard]] std::string getMD5() const;
    [[nodiscard]] std::vector<std::u32string> getParsedPages() const;
    [[nodiscard]] std::u32string getParsedPage(unsigned int page) const;
private:
    // Class Members
    std::u32string file_name_; // file name and extension, not a full path
    std::u32string path_; // absolute path of the file, including file name and extension
    std::string md5_hash_; // the md5 hash of the file. empty if it cannot be calculated
    std::vector<std::u32string> parsed_pages_; // contains the parsed text of each page of the file
    // Functions
    void setHash();
    void parsePages();
    void setInfo();
    void setFileName();
};
