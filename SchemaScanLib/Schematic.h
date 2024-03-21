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
#include "utils/SchemaUtils.h"

class Schematic {
public:
    Schematic(const std::wstring &fpath);
    ~Schematic(){};
    // Functions
    [[nodiscard]] std::wstring getFileName() const;
    [[nodiscard]] std::wstring getFilePath() const;
    [[nodiscard]] unsigned int getPageCount() const;
    [[nodiscard]] std::string getMD5() const;
    [[nodiscard]] std::vector<std::wstring> getParsedPages() const;
    [[nodiscard]] std::wstring getParsedPage(unsigned int page) const;
private:
    // Class Members
    std::wstring file_name_;
    std::wstring path_;
    unsigned int page_count_ = 0;
    std::string md5_hash_;
    std::vector<std::wstring> parsed_pages_;
    // Functions
    void setup(const std::wstring &fpath);
    void setHash();
    void parsePages();
    void setInfo();
    void setFileName();

};
