//
// Created by Andrew on 3/16/2024.
//

#include "SchemaUtils.h"

#include <string>
#include <codecvt>
#include <filesystem>

/**
 * Determines whether a file path is a direct path to a .pdf file
 * @param fpath The (absolute) file path that you wish to check
 * @return A boolean, whether the path points directly to a .pdf file
 */
bool SchemaUtils::isPdfFile(const std::u32string &fpath) {
    return std::filesystem::path(fpath).extension() == ".pdf";
}

/**
 * Determines whether a file path is a direct path to a .json file
 * @param fpath The (absolute) file path that you wish to check
 * @return A boolean, whether the path points directly to a .json file
 */
bool SchemaUtils::isJsonFile(const std::u32string &fpath) {
    return std::filesystem::path(fpath).extension() == ".json";
}

/**
 * Converts std::u32string to a std::string
 * @param u32_string The u32string to be converted
 * @return A converted std::string
 */
std::string SchemaUtils::u32StringToStdString(const std::u32string &u32_string) {
    static std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t > converter;
    return converter.to_bytes(u32_string);
}

/**
 * Converts std::string to std::u32string
 * @param string The std::string to be converted
 * @return A converted std::u32string
 */
std::u32string SchemaUtils::stdStringToU32String(const std::string &string) {
    static std::wstring_convert<std::codecvt_utf8<char32_t >, char32_t > converter;
    return converter.from_bytes(string);
}

