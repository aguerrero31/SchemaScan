//
// Created by Andrew on 3/16/2024.
//

#ifndef SCHEMASCAN_SCHEMATICHANDLER_H
#define SCHEMASCAN_SCHEMATICHANDLER_H

#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

#include "Schematic.h"
#include "utils/SchemaUtils.h"


class SchematicHandler {
public:
    SchematicHandler(const std::wstring &path);
    ~SchematicHandler();
    [[nodiscard]] int getSchematicCount() const;
    [[nodiscard]] int getFoundFilesCount() const;
private:
    void Scan();
    void Search();
    std::set<std::wstring> fpaths_;
    std::vector<Schematic*> schematics_;
    std::wstring base_directory_;
    int schematic_count_ = 0;
};


#endif //SCHEMASCAN_SCHEMATICHANDLER_H
