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
bool SchemaUtils::isPdfFile(const std::u32string &fpath) {
    return hasFileExt(fpath, ".pdf");
}

/**
 * Determines whether a file path is a direct path to a .json file
 * @param fpath The (absolute) file path that you wish to check
 * @return A boolean, whether the path points directly to a .json file
 */
bool SchemaUtils::isJsonFile(const std::u32string &fpath) {
    return hasFileExt(fpath, ".json");
}

/**
 * Determines whether a file path is a direct path to a file with a specific extension
 * @param fpath The (absolute) file path that you wish to check
 * @param extension The extension that you wish to check for (e.g. ".pdf")
 * @return A boolean, whether the path points at a file with said extension
 */
bool SchemaUtils::hasFileExt(const std::u32string &fpath, const std::string &extension) {
    return std::filesystem::path(fpath).extension() == extension;
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

/**
 * Strips all other path information from an absolute file path and returns just the file name (no extension). Works
 *      on paths with either / or \
 * @param fpath The (absolute) file path that you wish to get information from
 * @return
 */
std::u32string SchemaUtils::getNameFromPath(const std::u32string &fpath) {
    std::u32string fileName = getNameAndExtFromPath(fpath);
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
std::u32string SchemaUtils::getNameAndExtFromPath(const std::u32string &fpath) {
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
std::u32string SchemaUtils::getDirectoryFromPath(const std::u32string &fpath) {
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
std::set<std::u32string> SchemaUtils::searchDirectoryFor(const std::u32string &directory, const std::string &extension,
                                                         const fileNameType &type) {
    std::u32string prefix = U"\\\\?\\";
    std::set<std::u32string> found;
    // Prefix and directory option necessary for long file paths on Windows. Without these the iteration stops
    // and throws an error when it encounters a directory that's too long. The directory option also keeps the iterator
    // from throwing an error if it hits a directory or file that it doesn't have permission to access
    for (const auto &pathIt: std::filesystem::recursive_directory_iterator(
            prefix + directory, std::filesystem::directory_options::skip_permission_denied)) {
        if (hasFileExt(pathIt.path().u32string(), extension)) {
            std::u32string absPath = pathIt.path().u32string();
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

