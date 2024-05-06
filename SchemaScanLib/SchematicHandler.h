//
// Created by Andrew on 3/16/2024.
//

#ifndef SCHEMASCAN_SCHEMATICHANDLER_H
#define SCHEMASCAN_SCHEMATICHANDLER_H

#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <set>

#include "Schematic.h"
#include "utils/SchemaUtils.h"


class SchematicHandler {
public:
    SchematicHandler(const std::wstring &path);
    ~SchematicHandler();
    [[nodiscard]] int getSchematicCount() const;
    [[nodiscard]] int getFoundFilesCount() const;
    [[nodiscard]] int getSkippedSchematicCount() const;
    [[nodiscard]] std::vector<std::wstring> getSkippedSchematics() const;
    [[nodiscard]] std::vector<Schematic*> getSchematics() const;
    void cacheAll(const bool overwrite) const;
private:
    void Scan();
    void Search();
    std::set<std::wstring> fpaths_; // contains absolute paths of all files found, valid or invalid
    std::vector<Schematic*> schematics_; // contains valid parsed Schematic objects
    std::vector<std::wstring> skipped_schematic_paths_; // contains file paths of skipped schematics
    std::wstring base_directory_; // initial directory used to search for files
    std::set<std::string> hash_set_; // contains hashes of the valid parsed Schematic objects in schematics_
    std::wstring localAppDataPath; // Holds the path to the current user's %LOCALAPPDATA% path (user/AppData/local)
    std::wstring winCachePath; // Holds the Windows cache path for the user (currently user/AppData/local/SchemaScan/cache)
};


#endif //SCHEMASCAN_SCHEMATICHANDLER_H
