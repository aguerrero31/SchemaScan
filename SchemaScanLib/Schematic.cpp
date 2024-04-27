//
// Created by Andrew on 2/12/2024.
//

#include "Schematic.h"
#include "utils/SchemaUtils.h"

#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <set>

#include <podofo/podofo.h>
#include <hashlibpp.h>
#include <nlohmann/json.hpp>


/**
 * Default constructor for the Schematic class
 * @param fpath The absolute file path to a schematic
 * @throws out_of_range if the file path is incorrect, or if the file does not end in ".pdf"
 */
Schematic::Schematic(const std::u32string &fpath) {
    if (SchemaUtils::isPdfFile(fpath)) {
        this->path_ = fpath;
        this->setHash(); // always make sure setHash() is called before parsePages()
        this->setFileName();
        this->parsePages();
    } else {
        throw std::out_of_range("Incorrect file path or type");
    }
}

/**
 * Constructor that creates a Schematic object from a nlohmann::ordered_json object
 * @param jsonObj The ordered_json object that you wish to create a Schematic object from
 */
Schematic::Schematic(const nlohmann::ordered_json &jsonObj) {
    this->file_name_ = SchemaUtils::stdStringToU32String(jsonObj["name"]);
    this->path_ = SchemaUtils::stdStringToU32String(jsonObj["path"]);
    this->md5_hash_ = jsonObj["md5"];
    for (const std::string page : jsonObj["pages"]) {
        this->parsed_pages_.push_back(SchemaUtils::stdStringToU32String(page));
    }
}

/**
 * Parses the .pdf file contained at the path that the Schematic object was created with (path_). Reads the text one
 *      page at a time, and adds the u32string representation to the Schematic object's parsed_pages_ vector.
 * Utilizes the PoDoFo library
 */
void Schematic::parsePages() {
    PoDoFo::PdfMemDocument document;
    document.Load(SchemaUtils::u32StringToStdString(this->path_));
    auto &pages = document.GetPages();
    for (int i = 0; i < pages.GetCount(); ++i) {
        PoDoFo::PdfPage &page = pages.GetPageAt(i);
        std::vector<PoDoFo::PdfTextEntry> entries;
        page.ExtractTextTo(entries);
        std::u32string pageAsString;
        for (auto &entry: entries) {
            pageAsString += SchemaUtils::stdStringToU32String(entry.Text);
        }
        this->parsed_pages_.push_back(pageAsString);
    }
}

/**
 * Sets the md5_hash_ value of a Schematic object to the md5 representation of the file contained at the path_
 *      value of the Schematic object
 * Utilizes the hashlib2plus library
 * @return
 */
void Schematic::setHash() {
    hashwrapper *wrapper = new md5wrapper();
    std::string hash;
    try {
        hash = wrapper->getHashFromString(SchemaUtils::u32StringToStdString(this->path_));
    }
    catch (hlException &e) {
        std::cerr << "Error computing file hash | " << e.error_number() << " | " << e.error_message() << "\n";
    }
    delete wrapper;
    this->md5_hash_ = hash;
}

/**
 * Sets the file name of the Schematic object. Excludes all other path info, file name and extension only
 */
void Schematic::setFileName() {
    this->file_name_ = SchemaUtils::getNameAndExtFromPath(this->path_);
}

/**
 * Getter for the file name (extension included) contained in a Schematic object
 * @return A u32string, the file name
 */
std::u32string Schematic::getFileName() const {
    return this->file_name_;
}

/**
 * Getter for the file name (extension excluded) contained in a Schematic object
 * @return A u32string, the file name
 */
std::u32string Schematic::getFileNameNoExt() const {
    return this->file_name_.substr(0,this->file_name_.length()-4);
}

/**
 * Getter for the absolute file path (file name & extension included) contained in a Schematic object
 * @return A u32string, the absolute path
 */
std::u32string Schematic::getFilePath() const {
    return this->path_;
}

/**
 * Getter for the page count (number of pages parsed) of a Schematic object
 * @return An unsigned integer, the page count
 */
unsigned int Schematic::getPageCount() const {
    return this->parsed_pages_.size();
}

/**
 * Getter for the md5 hash of the file contained at the absolute path that the Schematic object was created with
 * @return A string, the md5 hash of the file
 */
std::string Schematic::getMD5() const {
    return this->md5_hash_;
}

/**
 * Getter for the parsed pages of a Schematic object
 * @return A vector of u32strings, containing the raw text contents of a parsed .pdf file
 */
std::vector<std::u32string> Schematic::getParsedPages() const {
    return this->parsed_pages_;
}

/**
 * Getter for a single parsed page of a Schematic object
 * @param page The number of the page you wish to retrieve
 * @throws out_of_range if the passed in value is not > 0, or is higher than the page count of the Schematic object
 * @return A u32string, the raw parsed text contents of the specific page of the .pdf file
 */
std::u32string Schematic::getParsedPage(const unsigned int page) const {
    if (page > 0 || page <= this->parsed_pages_.size()) {
        return this->parsed_pages_.at(page - 1);
    } else {
        throw std::out_of_range(std::format("Failed to retrieve page {}. The minimum value is 1, "
                                            "and the maximum is {}.",page,this->parsed_pages_.size()));
    }
}

// Searches a schematic object for a term, returning a map with the name and
//
std::map<std::string, std::vector<int>> Schematic::Search(const std::string &searchTerm, bool includePath) const {
//    std::map<std::string, std::vector<int>> containsTermMap;
//    for ()
    return std::map<std::string, std::vector<int>>{{}};
}

/**
 * Stores the json object representation of a Schematic object in a file, at a given path. Checks the cache directory
 *      for the file to see if it already exists, and will skip or overwrite it depending on the overwrite parameter
 * @param cacheDir A string, the directory where you want the file to be stored
 * @param overwrite A boolean, whether the file should be overwritten if it already exists
 */
void Schematic::cache(const std::u32string &cacheDir, const bool overwrite) {
    std::set<std::u32string> cachedFiles = SchemaUtils::searchDirectoryFor(cacheDir, ".json",
                                                                           SchemaUtils::fileNameType::Extension);
    auto outPath = SchemaUtils::u32StringToStdString(cacheDir + this->getFileNameNoExt() + U".json");
    if (std::filesystem::is_directory(cacheDir)) {
        if (cachedFiles.contains(this->getFileNameNoExt() + U".json") && !overwrite) {
            return;
        }
        nlohmann::ordered_json jsonObj = this->toJson();
        // TODO: Convert to wstring or something else to output proper file name, right now non-ASCII chars are garbage
        std::ofstream output(outPath);
        output << std::setw(4) << jsonObj << std::endl;
        output.close();
    }
    // TODO: Change this to an exception? Handle this another way instead of skipping?
    else {
        std::cerr << "Incorrect path (permissions issue, not absolute path, doesn't contain file name and extension,"
                     "etc), caching will be skipped for " << SchemaUtils::u32StringToStdString(this->path_)
                     << ". Entered path: " << outPath << "\n";
    }
}

// TODO: Does not work with u32string, check if it works with wstring (probably going to convert entire program to
//      wstring anyways). If it doesn't, might need to find another option... I think file names might be messed
//      up for converting from json file to Schematic obj
/**
 * Converts a Schematic object to an nlohmann::ordered_json object
 * @return nlohmann::ordered_json, a json representation of the Schematic object
 */
nlohmann::ordered_json Schematic::toJson() {
    auto jsonObj = nlohmann::ordered_json{
            {"name", SchemaUtils::u32StringToStdString(this->file_name_)},
            {"path", SchemaUtils::u32StringToStdString(this->path_)},
            {"md5", this->md5_hash_},
            {"pageCount", this->getPageCount()},
            {"pages", nlohmann::ordered_json::array()}
    };
    for (int i = 1; i <= this->getPageCount(); ++i) {
        jsonObj["pages"].push_back({SchemaUtils::u32StringToStdString(this->getParsedPage(i))});
    }
    return jsonObj;
}


