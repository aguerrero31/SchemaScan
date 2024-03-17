//
// Created by Andrew on 2/12/2024.
//

#pragma once

#include <memory>
#include <iostream>
#include <filesystem>
#include <stdexcept>
#include <vector>
#include <string>

#include <podofo/podofo.h>

class Schematic {
public:
    Schematic(const std::string &fpath);
    ~Schematic(){};
    // Functions
    [[nodiscard]] std::string getFileName() const;
    [[nodiscard]] std::string getFilePath() const;
    [[nodiscard]] unsigned int getPageCount() const;
    [[nodiscard]] std::string getMD5() const;
    [[nodiscard]] std::vector<std::string> getParsedPages() const;
    [[nodiscard]] std::string getParsedPage(unsigned int page) const;
private:
    // Class Members
    std::string file_name_;
    std::string path_;
    unsigned int page_count_ = 0;
    std::string md5_hash_;
    std::vector<std::string> parsed_pages_;
    // Functions
    void setup(const std::string &fpath);
    void setHash();
    void parsePages();
    void setInfo();
    void setFileName();
};
