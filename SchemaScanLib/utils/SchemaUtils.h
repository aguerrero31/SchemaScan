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
    static bool isPdfFile(const std::wstring &fpath);
    static bool isJsonFile(const std::wstring &fpath);
    static bool hasFileExt(const std::wstring &fpath, const std::string &extension);
    static std::string u32StringToStdString(const std::u32string &u32_string);
    static std::u32string stdStringToU32String(const std::string &str);
    static std::string wstringToStdString(const std::wstring &w_string);
    static std::wstring stdStringToWString(const std::string &str);
    static std::wstring getNameFromPath(const std::wstring &fpath);
    static std::wstring getNameAndExtFromPath(const std::wstring &fpath);
    static std::wstring getDirectoryFromPath(const std::wstring &fpath);
    static std::set<std::wstring> searchDirectoryFor(const std::wstring &directory, const std::string &extension,
                                                       const fileNameType &type = fileNameType::Absolute);
};


#endif //SCHEMASCAN_SCHEMAUTILS_H
