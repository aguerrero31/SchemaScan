//
// Created by Andrew on 3/16/2024.
//

#include "SchemaUtils.h"

#include <string>
#include <codecvt>
#include <filesystem>
#include <set>

/**
 * Determines whether a file path is a direct path to a .pdf file
 * @param fpath The (absolute) file path that you wish to check
 * @return A boolean, whether the path points directly to a .pdf file
 */
bool SchemaUtils::isPdfFile(const std::wstring &fpath) {
    return hasFileExt(fpath, ".pdf");
}

/**
 * Determines whether a file path is a direct path to a .json file
 * @param fpath The (absolute) file path that you wish to check
 * @return A boolean, whether the path points directly to a .json file
 */
bool SchemaUtils::isJsonFile(const std::wstring &fpath) {
    return hasFileExt(fpath, ".json");
}

/**
 * Determines whether a file path is a direct path to a file with a specific extension
 * @param fpath The (absolute) file path that you wish to check
 * @param extension The extension that you wish to check for (e.g. ".pdf")
 * @return A boolean, whether the path points at a file with said extension
 */
bool SchemaUtils::hasFileExt(const std::wstring &fpath, const std::string &extension) {
    return std::filesystem::path(fpath).extension() == extension;
}

/**
 * Converts std::wstring to a std::string
 * @param u32_string The u32string to be converted
 * @return A converted std::string
 */
std::string SchemaUtils::u32StringToStdString(const std::u32string &u32_string) {
    static std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t > converter;
    return converter.to_bytes(u32_string);
}

/**
 * Converts std::string to std::wstring
 * @param string The std::string to be converted
 * @return A converted std::wstring
 */
std::u32string SchemaUtils::stdStringToU32String(const std::string &str) {
    static std::wstring_convert<std::codecvt_utf8<char32_t >, char32_t > converter;
    return converter.from_bytes(str);
}

/**
 * Converts a std::wstring to std::string
 * @param w_string
 * @return
 */
std::string SchemaUtils::wstringToStdString(const std::wstring &w_string) {
    static std::wstring_convert<std::codecvt_utf8<wchar_t >, wchar_t > converter;
    return converter.to_bytes(w_string);
}

// Converts a std::string to std::wstring
std::wstring SchemaUtils::stdStringToWString(const std::string &str) {
    static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> converter;
    return converter.from_bytes(str);
}

/**
 * Strips all other path information from an absolute file path and returns just the file name (no extension). Works
 *      on paths with either / or \
 * @param fpath The (absolute) file path that you wish to get information from
 * @return
 */
std::wstring SchemaUtils::getNameFromPath(const std::wstring &fpath) {
    std::wstring fileName = getNameAndExtFromPath(fpath);
    if (fileName.find('.') != std::string::npos) {
        std::size_t foundAt = fileName.find_last_of('.');
        return fileName.substr(0, foundAt);
    }
    return fpath;
}

/**
 * Strips all other path information from an absolute file path and returns the file name with extension. Works on
 *      paths with either / or \
 * @param fpath The (absolute) file path that you wish to get information from
 * @return
 */
std::wstring SchemaUtils::getNameAndExtFromPath(const std::wstring &fpath) {
    std::size_t foundAt;
    if (fpath.find('/') != std::string::npos) {
        foundAt = fpath.find_last_of('/');
    }
    else {
        foundAt = fpath.find_last_of('\\');
    }
    return fpath.substr(foundAt + 1);
}

/**
 * Strips the file information fromm an absolute file path and returns the directory information, ending with a \ or /
 * @param fpath The (absolute) file path that you wish to get information from
 * @return
 */
std::wstring SchemaUtils::getDirectoryFromPath(const std::wstring &fpath) {
    std::size_t foundAt;
    if (fpath.find('/') != std::string::npos) {
        foundAt = fpath.find_last_of('/');
    }
    else {
        foundAt = fpath.find_last_of('\\');
    }
    return fpath.substr(0, foundAt + 1);
}

/**
 * Recursively search a directory and get all file names with a given extension. Absolute paths are default, pass in
 *      a fileNameType if you want the file name with the extension included, or the file name without the extension
 *      instead.
 * @param directory The directory that you wish to search
 * @param extension The file extension that you are looking for (e.g. ".pdf")
 * @param type Default Absolute. A fileNameType enum that determines the type of string(s) that you will get back
 * @return A set of
 */
std::set<std::wstring> SchemaUtils::searchDirectoryFor(const std::wstring &directory, const std::string &extension,
                                                         const fileNameType &type) {
    std::wstring prefix = L"\\\\?\\";
    std::set<std::wstring> found;
    // Prefix and directory option necessary for long file paths on Windows. Without these the iteration stops
    // and throws an error when it encounters a directory that's too long. The directory option also keeps the iterator
    // from throwing an error if it hits a directory or file that it doesn't have permission to access
    for (const auto &pathIt: std::filesystem::recursive_directory_iterator(
            prefix + directory, std::filesystem::directory_options::skip_permission_denied)) {
        if (hasFileExt(pathIt.path().wstring(), extension)) {
            std::wstring absPath = pathIt.path().wstring();
            if (type == fileNameType::Extension) {
                found.insert(getNameAndExtFromPath(absPath));
            }
            else if (type == fileNameType::NoExtension) {
                found.insert(getNameFromPath(absPath));
            }
            else {
                found.insert(absPath);
            }
        }
    }
    return found;
}

