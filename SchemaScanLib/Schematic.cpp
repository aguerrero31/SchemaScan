//
// Created by Andrew on 2/12/2024.
//

#include "Schematic.h"

/**
 * TODO: Currently some files cannot be hashed, unsure of why. These files seem to open fine, but the hash can't
 *      be computed, and it cannot be parsed. Currently skipping this file by checking the hash in parsePages() for
 *      emptiness. Look into a fix for this, or restructure the code to find a better spot to check. Also need to
 *      maybe invalidate this object?
 */

/**
 * Default constructor for the Schematic class
 * @param fpath The absolute file path to a schematic
 * @throws out_of_range if the file path is incorrect, or if the file does not end in ".pdf"
 */
Schematic::Schematic(const std::u32string &fpath) {
    if (SchemaUtils::isPdfFile(fpath)) {
        this->path_ = fpath;
        this->setHash(); // always make sure setHash() is called before parsePages()
        this->setInfo();
        this->setFileName();
        this->parsePages();
    } else {
        throw std::out_of_range("Incorrect file path or type");
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
 * Sets extra information for the Schematic object
 * TODO: Keep or remove?
 */
void Schematic::setInfo() {

}

/**
 * Sets the file name of the Schematic object. Excludes all other path info, file name and extension only
 */
void Schematic::setFileName() {
    std::size_t found = this->path_.find_last_of('/');
    this->file_name_ = this->path_.substr(found + 1);
}

/**
 * Getter for the file name (extension included) contained in a Schematic object
 * @return A u32string, the file name
 */
std::u32string Schematic::getFileName() const {
    return this->file_name_;
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
std::u32string Schematic::getParsedPage(unsigned int page) const {
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
}
