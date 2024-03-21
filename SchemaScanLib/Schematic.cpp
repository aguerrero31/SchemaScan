//
// Created by Andrew on 2/12/2024.
//

#include "Schematic.h"

#include <hashlibpp.h>

/**
 * Default constructor for the Schematic class
 * @param fpath The absolute file path to a schematic
 * @throws out_of_range if the file path is incorrect, or if the file does not end in ".pdf"
 */
Schematic::Schematic(const std::wstring &fpath) {
    if (SchemaUtils::isPdfFile(fpath)) {
        this->path_ = fpath;
        this->setHash();
        this->setInfo();
        this->setFileName();
        this->parsePages();
    } else {
        std::cout << "Incorrect file path or type, cannot create Schematic object from: "
                    << SchemaUtils::wStringToString(fpath) << "\n";
        throw std::out_of_range("Incorrect file path or type, skipping");
    }
}

/**
 * Setup function for a Schematic object. Sets private class members like the file path, the hash, file name, etc.
 * Additionally calls parsePages() to parse all of the pages in the .pdf
 * @param fpath The absolute file path to a schematic
 */
void Schematic::setup(const std::wstring &fpath) {
    // TODO: Remove this function? Moved everything to constructor
}

/**
 * Parses the .pdf file contained at the path that the Schematic object was created with (path_). Reads the text one
 *      page at a time, and adds the wstring representation to the Schematic object's parsed_pages_ vector.
 * Utilizes the PoDoFo library
 */
void Schematic::parsePages() {
    PoDoFo::PdfMemDocument document;
    document.Load(SchemaUtils::wStringToString(this->path_));
    auto &pages = document.GetPages();
    for (int i = 0; i < pages.GetCount(); ++i) {
        PoDoFo::PdfPage &page = pages.GetPageAt(i);
        std::vector<PoDoFo::PdfTextEntry> entries;
        page.ExtractTextTo(entries);
        std::wstring pageAsString;
        for (auto &entry: entries) {
            pageAsString += SchemaUtils::stringToWString(entry.Text);
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
        hash = wrapper->getHashFromFile(SchemaUtils::wStringToString(this->path_));
    }
    catch (hlException &e) {
        std::cerr << "Error computing file hash | " << e.error_number() << " | " << e.error_message() << "\n";
    }
    delete wrapper;
    this->md5_hash_ = hash;
}

/**
 * Sets extra information for the Schematic object. Currently only does the page count, but will be expanded to
 *      more in the future
 * TODO: ADD MORE FUNCTIONALITY OR CHANGE TO setPageCount()
 */
void Schematic::setInfo() {
    PoDoFo::PdfMemDocument document{};
    document.Load(SchemaUtils::wStringToString(this->path_));
    std::vector<PoDoFo::PdfTextEntry> entries;
    PoDoFo::PdfPageCollection &pages = document.GetPages();
    this->page_count_ = pages.GetCount();
}

/**
 * Gets the file name from the absolute path of the Schematic object
 * @return A wstring containing the file name
 */
void Schematic::setFileName() {
    std::size_t found = this->path_.find_last_of('/');
    this->file_name_ = this->path_.substr(found + 1);
}

/**
 * Getter for the file name (extension included) contained in a Schematic object
 * @return A wstring, the file name
 */
std::wstring Schematic::getFileName() const {
    return this->file_name_;
}

/**
 * Getter for the absolute file path (file name & extension included) contained in a Schematic object
 * @return A wstring, the absolute path
 */
std::wstring Schematic::getFilePath() const {
    return this->path_;
}

/**
 * Getter for the page count (number of pages parsed) of a Schematic object
 * @return An unsigned integer, the page count
 */
unsigned int Schematic::getPageCount() const {
    return this->page_count_;
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
 * @return A vector of wstrings, containing the raw text contents of a parsed .pdf file
 */
std::vector<std::wstring> Schematic::getParsedPages() const {
    return this->parsed_pages_;
}

/**
 * Getter for a single parsed page of a Schematic object
 * @param page The number of the page you wish to retrieve
 * @throws out_of_range if the passed in value is not > 0, or is higher than the page count of the Schematic object
 * @return A wstring, the raw parsed text contents of the specific page of the .pdf file
 */
std::wstring Schematic::getParsedPage(unsigned int page) const {
    if (page > 0 || page <= this->page_count_) {
        return this->parsed_pages_.at(page - 1);
    } else {
        throw std::out_of_range(std::format("Failed to retrieve page {}. The minimum value is 1, "
                                            "and the maximum is {}.",page,this->page_count_));
    }
}
