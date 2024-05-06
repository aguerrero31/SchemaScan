//
// Created by Andrew on 2/12/2024.
//

#pragma once

#include <vector>
#include <string>
#include <map>
#include <nlohmann/json.hpp>
#include <hashlibpp.h>

class Schematic {
public:
    Schematic(const std::wstring &fpath);
    Schematic(const nlohmann::ordered_json &jsonObj);
    // Functions
    std::map<std::string, std::vector<int>> Search(const std::string &searchTerm, bool includePath) const;
    [[nodiscard]] std::wstring getFileName() const;
    [[nodiscard]] std::wstring getFileNameNoExt() const;
    [[nodiscard]] std::wstring getFilePath() const;
    [[nodiscard]] unsigned int getPageCount() const;
    [[nodiscard]] std::string getMD5() const;
    [[nodiscard]] std::vector<std::string> getParsedPages() const;
    [[nodiscard]] std::string getParsedPage(const unsigned int page) const;
    void cache(const std::wstring &cacheDir, const bool overwrite);
private:
    // Class Members
    std::wstring file_name_; // file name and extension, not a full path
    std::wstring path_; // absolute path of the file, including file name and extension
    std::string md5_hash_; // the md5 hash of the file. empty if it cannot be calculated
    std::vector<std::string> parsed_pages_; // contains the parsed text of each page of the file
    // Functions
    void setHash();
    void parsePages();
    void setFileName();
    nlohmann::ordered_json toJson();
};
