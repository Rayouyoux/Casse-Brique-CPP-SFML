#include "LevelManager.h"

std::vector<std::string> LevelManager::FileManager(std::string sFilePath) {
    std::vector<std::string> lines; // Vector to store lines

    std::ifstream file(sFilePath); // Open the file

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }

        file.close(); // Close the file
    }
    else {
        std::cerr << "Error opening file: " << sFilePath << std::endl;
    }

    return lines;

}