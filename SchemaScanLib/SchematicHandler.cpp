//
// Created by Andrew on 3/16/2024.
//

#include "SchematicHandler.h"
#include "utils/SchemaUtils.h"

#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <set>
#include <initguid.h>
#include <ShlObj.h>
#include <KnownFolders.h>

#include <hashlibpp.h>
#include <nlohmann/json.hpp>

// Constructors / Destructor

SchematicHandler::SchematicHandler(const std::wstring &path) {
    this->base_directory_ = path;
    // Get %APPDATA% path and create directories
    PWSTR LADPath = nullptr;
    auto temp = SHGetKnownFolderPath(FOLDERID_ProgramFiles,0,NULL,&LADPath);
    this->localAppDataPath = std::wstring(LADPath);
    this->winCachePath = this->localAppDataPath + L"\\SchemaScan\\cache";
    CoTaskMemFree(LADPath);
    if (!std::filesystem::exists(this->localAppDataPath + L"\\SchemaScan") ||
                                        !std::filesystem::exists(this->winCachePath)) {
        try {
            std::filesystem::create_directory(localAppDataPath + L"\\SchemaScan");
            std::filesystem::create_directory(winCachePath);
        }
        catch (std::filesystem::filesystem_error &e) {
            std::cerr << "Could not create cache directory: " << e.what() << "\n";
            abort();
        }
    }
    // ------------------
    if (SchemaUtils::isPdfFile(path)) {
        std::cout << "Given path points directly at a single schematic: " << "\n";
    }
    Search();
    Scan();
}

SchematicHandler::~SchematicHandler() {
    for (Schematic *schematic : schematics_) {
        delete schematic;
    }
}

// General Functions

/**
 * Scans all .pdf files in the SchematicHandler's fpaths_ object. Skips files with an incorrect path, files whose
 *      md5 hash could not be calculated, or files that fail parsing for any reason. Search() should typically be
 *      called before this function to ensure that fpaths_ actually has items in it
 */
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
            std::wcerr << "Incorrect file path or type, skipping creation of Schematic object: " << path << "\n";
            skipped_schematic_paths_.push_back(path);
        }
        catch (const hlException&) {
            std::wcerr << "Could not get hash of file, skipping creation of Schematic object: " << path << "\n";
            skipped_schematic_paths_.push_back(path);
        }
        catch (...) {
            std::wcerr << "Could not parse pdf file (or other error), skipping creation of Schematic object: "
                      << path << "\n";
            skipped_schematic_paths_.push_back(path);
        }
    }
}

/**
 * Searches a SchematicHandler's base_directory_ recursively for all .pdf files, adding the absolute path (file name
 *      and extension included) to the fpaths_ object. Typically called before Scan() to populate the list of files,
 *      otherwise there will be nothing to scan
 */
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
        std::wcout << "Found Schematic: " << path_str << "\n";
    }
}

/**
 * Cache a .json representation of all Schematic objects in a SchematicHandler
 * @param cacheDir The directory that the cache files will be stored at
 * @param overwrite A boolean, whether to overwrite a file that already exists
 */
void SchematicHandler::cacheAll(const bool overwrite) const {
    for (auto &schem : this->schematics_) {
        schem->cache(this->winCachePath, overwrite);
    }
}

// Getters

/**
 * Get the amount of files found by the Search() function. These are not necessarily all valid, some may fail to
 *      be turned into Schematic objects for various reasons (see Scan())
 * @return an integer
 */
int SchematicHandler::getFoundFilesCount() const {
    return int(this->fpaths_.size());
}

/**
 * Get the amount of Schematic objects in the SchematicHandler. These are all guaranteed valid
 * @return an integer
 */
int SchematicHandler::getSchematicCount() const {
    return int(this->schematics_.size());
}

/**
 * Get all of the Schematic objects contained in the SchematicHandler
 * @return a vector of pointers to Schematic objects
 */
std::vector<Schematic *> SchematicHandler::getSchematics() const {
    return this->schematics_;
}

/**
 * Get the amount of .pdf files that could not be converted into Schematic objects for any reason
 * @return An integer
 */
int SchematicHandler::getSkippedSchematicCount() const {
    return int(this->skipped_schematic_paths_.size());
}

/**
 * Get the absolute paths (file names included) for the .pdf files that could not be converted into Schematic objects
 *      for any reason
 * @return A vector of std::wstrings
 */
std::vector<std::wstring> SchematicHandler::getSkippedSchematics() const {
    return this->skipped_schematic_paths_;
}