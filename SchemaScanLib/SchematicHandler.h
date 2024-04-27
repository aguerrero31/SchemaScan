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
    SchematicHandler(const std::u32string &path);
    ~SchematicHandler();
    [[nodiscard]] int getSchematicCount() const;
    [[nodiscard]] int getFoundFilesCount() const;
    [[nodiscard]] int getSkippedSchematicCount() const;
    [[nodiscard]] std::vector<std::u32string> getSkippedSchematics() const;
    [[nodiscard]] std::vector<Schematic*> getSchematics() const;
    void cacheAll(const std::u32string &cacheDir, const bool overwrite) const;
private:
    void Scan();
    void Search();
    std::set<std::u32string> fpaths_; // contains absolute paths of all files found, valid or invalid
    std::vector<Schematic*> schematics_; // contains valid parsed Schematic objects
    std::vector<std::u32string> skipped_schematic_paths_; // contains file paths of skipped schematics (failed to calculate hash which means it would likely fail to scan)
    std::u32string base_directory_; // initial directory used to search for files
    std::set<std::string> hash_set_; // contains hashes of the valid parsed Schematic objects in schematics_.
                                     // used to weed out duplicates
};


#endif //SCHEMASCAN_SCHEMATICHANDLER_H
