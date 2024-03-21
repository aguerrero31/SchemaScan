//
// Created by Andrew on 3/16/2024.
//

#include "SchemaUtils.h"
#include <filesystem>

/**
 * Determines whether a file path is a direct path to a pdf file
 * @param fpath The (absolute) file path that you wish to check
 * @return A boolean, whether the path points directly to a pdf file
 */
bool SchemaUtils::isPdfFile(const std::wstring &fpath) {
    return std::filesystem::path(fpath).extension() == ".pdf";
}

// Converts a std::wstring to std::string
std::string SchemaUtils::wStringToString(const std::wstring &w_string) {
    static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t > converter;
    return converter.to_bytes(w_string);
}

std::wstring SchemaUtils::stringToWString(const std::string &string) {
    static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t > converter;
    return converter.from_bytes(string);
}

