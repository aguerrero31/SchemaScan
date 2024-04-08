//
// Created by Andrew on 3/16/2024.
//

#include "SchematicHandler.h"

SchematicHandler::SchematicHandler(const std::u32string &path) {
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
// Catches all exceptions thrown during Schematic object creation, and skips adding to vector if any throws occur
void SchematicHandler::Scan() {
    for (const auto &path : fpaths_) {
        try {
            auto temp = new Schematic(path);
            // Hash should be unique, and should not be empty (empty = unable to calculate hash and scan)
            if (hash_set_.insert(temp->getMD5()).second && !temp->getMD5().empty()) {
                schematics_.push_back(temp);
            }
            else {
                delete temp;
            }
        }
        catch (const std::out_of_range&) {
            std::cerr << "Incorrect file path or type, skipping creation of Schematic object: "
                      << SchemaUtils::u32StringToStdString(path) << "\n";
            skipped_schematic_paths_.push_back(path);
        }
        catch (const hlException&) {
            std::cerr << "Could not get hash of file, skipping creation of Schematic object: "
                      << SchemaUtils::u32StringToStdString(path) << "\n";
            skipped_schematic_paths_.push_back(path);
        }
        catch (...) {
            std::cerr << "Could not parse pdf file (or other error), skipping creation of Schematic object: "
                      << SchemaUtils::u32StringToStdString(path) << "\n";
            skipped_schematic_paths_.push_back(path);
        }
    }
}

// Searches the directory recursively for all schematics (ensures they're .pdf files), and adds the full path to fpaths_
void SchematicHandler::Search() {
    std::u32string prefix = U"\\\\?\\";
    try {
        // Prefix and directory option necessary for long file paths on Windows. Without these the iteration stops
        // and throws an error when it encounters a path that's too long. The directory option also keeps the iterator
        // from throwing an error if it hits a directory or file that it doesn't have permission to access
        for (const auto &pathIt : std::filesystem::recursive_directory_iterator(
                prefix + base_directory_, std::filesystem::directory_options::skip_permission_denied)) {
            if (SchemaUtils::isPdfFile(pathIt.path().u32string())) {
                fpaths_.insert(pathIt.path().u32string());
            }
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Caught exception during SchematicHandler::Search(). Error: " << e.what() << "\n";
        std::cout << "Cannot search directory, likely due to an incorrect file path. Please try again\n";
    }
    // TODO: Remove this? Just used for testing, but maybe useful for the final program?
    for (const auto &path_str : fpaths_) {
        std::cout << "Found Schematic: " << SchemaUtils::u32StringToStdString(path_str) << "\n";
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
    return int(this->skipped_schematic_paths_.size());
}

std::vector<std::u32string> SchematicHandler::getSkippedSchematics() const {
    return this->skipped_schematic_paths_;
}
