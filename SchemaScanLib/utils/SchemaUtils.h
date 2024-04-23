//
// Created by Andrew on 3/16/2024.
//

#ifndef SCHEMASCAN_SCHEMAUTILS_H
#define SCHEMASCAN_SCHEMAUTILS_H

#include <string>
#include <codecvt>

class SchemaUtils {
public:
    static bool isPdfFile(const std::u32string &fpath);
    static bool isJsonFile(const std::u32string &fpath);
    static std::string u32StringToStdString(const std::u32string &u32_string);
    static std::u32string stdStringToU32String(const std::string &string);
};


#endif //SCHEMASCAN_SCHEMAUTILS_H
