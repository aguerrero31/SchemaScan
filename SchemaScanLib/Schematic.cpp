//
// Created by Andrew on 2/12/2024.
//

#include "Schematic.h"

/**
 * Default constructor for the Schematic class
 * @param fpath The absolute file path to a schematic
 * @throws out_of_range if the file path is incorrect, or if the file does not end in ".pdf"
 */
Schematic::Schematic(const std::string &fpath) {
    if (std::filesystem::path(fpath).extension() == ".pdf") {
        this->path_ = fpath;
        this->md5_hash_ = this->setHash();
        parsePages();
    }
    else {
        std::cerr << "Incorrect file path or type, cannot create Schematic object: " << fpath << "\n";
        throw std::out_of_range("Incorrect file path or type, skipping");
    }
}

// TODO: Might be unused, need to look into whether anything needs to be done here with smart pointers
Schematic::~Schematic() {

}

/**
 * Parses the .pdf file contained at the path that the Schematic object was created with (path_). Reads the text one
 *      page at a time, and adds the string representation to the Schematic object's parsed_pages_ vector.
 * Utilizes the PoDoFo library
 * @return void
 */
void Schematic::parsePages() {
    PoDoFo::PdfMemDocument document;
    document.Load(this->path_);
    PoDoFo::PdfPageCollection &pages = document.GetPages();
    for (int i = 0; i < pages.GetCount(); ++i) {
        PoDoFo::PdfPage &page = pages.GetPageAt(i);
        std::vector<PoDoFo::PdfTextEntry> entries;
        page.ExtractTextTo(entries);
        std::string pageAsString;
        for (auto &entry : entries) {
            pageAsString += entry.Text;
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
        hash = wrapper->getHashFromFile(this->path_);
    }
    catch (hlException &e){
        std::cerr << "Error computing file hash | " << e.error_number() << " | " << e.error_message() << "\n";
    }
    delete wrapper;
    this->md5_hash_ = hash;
}

void Schematic::setInfo() {

}

/**
 * Gets the file name from the absolute path of the Schematic object
 * @return A string containing the file name
 */
void Schematic::setFileName() {
    std::size_t found = this->path_.find_last_of('/');
    this->file_name_ = this->path_.substr(found+1);
}
