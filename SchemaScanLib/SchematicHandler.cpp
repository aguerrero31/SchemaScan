//
// Created by Andrew on 3/16/2024.
//

#include "SchematicHandler.h"

SchematicHandler::SchematicHandler(const std::wstring &path) {
    base_directory_ = path;
    if (SchemaUtils::isPdfFile(path)) {
        std::cout << "Given path points directly at a single schematic: " << "\n";
    }
    Search();
    Scan();
}

// Destructor
SchematicHandler::~SchematicHandler() {
    for (Schematic *schematic : schematics_) {
        delete schematic;
    }
}

// Scans all Schematics gathered from Search()
// Includes error checking via checking for empty hash
void SchematicHandler::Scan() {
    for (const auto &path : fpaths_) {
        try {
            auto temp = new Schematic(path);
            // Hash should be unique, and should not be empty (empty = unable to calculate hash and scan)
            if (hash_set_.insert(temp->getMD5()).second && !temp->getMD5().empty()) {
                schematics_.push_back(temp);
            }
            else {
                this->skipped_schematics_.push_back(temp->getFilePath());
                delete temp;
            }
        }
        catch (const std::out_of_range &e) {
            std::cerr << "Incorrect file path or type, cannot create Schematic object from file. Skipping "
                      << SchemaUtils::wStringToString(path) << "\n";
        }
    }
}

// Searches the directory recursively for all schematics (ensures they're .pdf files), and adds the full path to fpaths_
void SchematicHandler::Search() {
    std::wstring prefix = L"\\\\?\\";
    try {
        // Prefix and directory option necessary for long file paths on Windows. Without these the iteration stops
        // and throws an error when it encounters a path that's too long. The directory option also keeps the iterator
        // from throwing an error if it hits a directory or file that it doesn't have permission to access
        for (const auto &pathIt : std::filesystem::recursive_directory_iterator(
                prefix + base_directory_, std::filesystem::directory_options::skip_permission_denied)) {
            if (SchemaUtils::isPdfFile(pathIt.path().wstring())) {
                fpaths_.insert(pathIt.path().wstring());
            }
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Caught exception during SchematicHandler::Search(). Error: " << e.what() << "\n";
        std::cout << "Cannot search directory, likely due to an incorrect file path. Please try again\n";
    }
    // TODO: Remove this? Just used for testing, but maybe useful for the final program?
    for (const auto &path_str : fpaths_) {
        std::cout << "Found Schematic: " << SchemaUtils::wStringToString(path_str) << "\n";
    }
}

int SchematicHandler::getFoundFilesCount() const {
    return int(this->fpaths_.size());
}

int SchematicHandler::getSchematicCount() const {
    return int(this->schematics_.size());
}

std::vector<Schematic *> SchematicHandler::getSchematics() const {
    return this->schematics_;
}

int SchematicHandler::getSkippedSchematicCount() const {
    return int(this->skipped_schematics_.size());
}

std::vector<std::wstring> SchematicHandler::getSkippedSchematics() const {
    return this->skipped_schematics_;
}
