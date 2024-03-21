//
// Created by Andrew on 3/16/2024.
//

#include "SchematicHandler.h"

SchematicHandler::SchematicHandler(const std::wstring &path) {
    base_directory_ = path;
    // Path links directly to a file
    if (SchemaUtils::isPdfFile(path)) {
        std::cout << "Given path points directly at a single schematic: " << SchemaUtils::wStringToString(path) << "\n";
        schematics_.push_back(new Schematic(path));
        schematic_count_ = 1;
    }
    // Path is a directory
    else {
        Search();
    }
    Scan();
}

// Destructor
SchematicHandler::~SchematicHandler() {
    // Delete all schematic pointers
    for (Schematic *schematic : schematics_) {
        delete schematic;
    }
}

// Scans all Schematics gathered from Search()
void SchematicHandler::Scan() {
    // increment schematic count
    // this->schematics_.push_back(new Schematic(path));
    for (const auto &path : fpaths_) {

    }
}

// Searches the directory recursively for all schematics (ensures they're .pdf files), and adds the full path to fpaths_
// Have to use wstring because of Chinese or other language characters
void SchematicHandler::Search() {
    try {
        // TODO : Now breaking with very long file paths, restructure so it can catch those and continue somehow
        for (const auto &pathIt : std::filesystem::recursive_directory_iterator(base_directory_)) {
            if (SchemaUtils::isPdfFile(pathIt.path().wstring())) {
                fpaths_.insert(pathIt.path().wstring());
            }
        }
    }
    catch (...) {
        std::cout << "idk lol something broke";
    }

    for (const auto &path_str : fpaths_) {
        std::cout << "Found Schematic: " << SchemaUtils::wStringToString(path_str) << "\n";
    }
}

int SchematicHandler::getFoundFilesCount() const {
    return int(fpaths_.size());
}

int SchematicHandler::getSchematicCount() const {
    return schematic_count_;
}
