//
// Created by Andrew on 3/16/2024.
//

#ifndef SCHEMASCAN_SCHEMAUTILS_H
#define SCHEMASCAN_SCHEMAUTILS_H

#include <string>
#include <codecvt>
#include <set>

class SchemaUtils {
public:
    enum class fileNameType {
        Absolute,
        Extension,
        NoExtension
    };
    static bool isPdfFile(const std::u32string &fpath);
    static bool isJsonFile(const std::u32string &fpath);
    static bool hasFileExt(const std::u32string &fpath, const std::string &extension);
    static std::string u32StringToStdString(const std::u32string &u32_string);
    static std::u32string stdStringToU32String(const std::string &string);
    static std::u32string getNameFromPath(const std::u32string &fpath);
    static std::u32string getNameAndExtFromPath(const std::u32string &fpath);
    static std::u32string getDirectoryFromPath(const std::u32string &fpath);
    static std::set<std::u32string> searchDirectoryFor(const std::u32string &directory, const std::string &extension,
                                                       const fileNameType &type = fileNameType::Absolute);
};


#endif //SCHEMASCAN_SCHEMAUTILS_H
