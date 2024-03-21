//
// Created by Andrew on 3/16/2024.
//

#ifndef SCHEMASCAN_SCHEMAUTILS_H
#define SCHEMASCAN_SCHEMAUTILS_H

#include <string>
#include <codecvt>

class SchemaUtils {
public:
    static bool isPdfFile(const std::wstring &fpath);
    static std::string wStringToString(const std::wstring &w_string);
    static std::wstring stringToWString(const std::string &string);
};


#endif //SCHEMASCAN_SCHEMAUTILS_H
