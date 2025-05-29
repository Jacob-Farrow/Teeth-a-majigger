#ifndef TEETH_FILEUTIL_H
#define TEETH_FILEUTIL_H

#include <filesystem>
#include <iostream>

/**
 * @namespace FileUtil
 * @brief A utility namespace for file-related operations.
 *
 * The `FileUtil` namespace provides helper functions to manage and retrieve
 * file paths, such as the path to the assets directory.
 */
namespace FileUtil {

    /**
     * @brief Retrieves the path to the assets directory.
     *
     * This function calculates the path to the `assets` directory relative
     * to the current working directory of the executable.
     *
     * @return A `std::filesystem::path` object representing the path to the
     *         `assets` directory.
     */
    static std::filesystem::path getAssetsPath() {
        std::filesystem::path exePath = std::filesystem::current_path();
        return exePath / "assets";
    }
};

#endif //TEETH_FILEUTIL_H
