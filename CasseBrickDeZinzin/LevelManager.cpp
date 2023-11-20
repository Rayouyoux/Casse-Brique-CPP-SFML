#include "LevelManager.h"

std::vector<std::string> LevelManager::fileToText(const char* sFilePath) {
    std::vector<std::string> asLevel;
    std::ifstream fLevel(sFilePath);
    std::string sLine;

    if (fLevel) {
        while (std::getline(fLevel, sLine)) {
            asLevel.push_back(sLine.substr(0, 11));
        }
        fLevel.close();
    }
    else {
        if (fLevel.bad()) {
            std::cerr << "Error opening file (bad bit is set)" << std::endl;
        }
        else if (fLevel.fail()) {
            std::cerr << "Error opening file (fail bit is set)" << std::endl;
        }
        else if (fLevel.eof()) {
            std::cerr << "Error opening file (end-of-file reached)" << std::endl;
        }
        std::cerr << "Unable to open file: " << sFilePath << std::endl; // Print attempted file path
    }


    return asLevel;
}


void LevelManager::createLevel(std::vector<std::string> asLevel) {
    std::map<char, std::string> levelInformation;

    for (int i = 3; i < asLevel.size(); i++) {
        levelInformation[asLevel[i][0]] = asLevel[i].substr(1);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 11; j++) {
            Brick* oBrick = new Brick(std::stoi(levelInformation[asLevel[i][j]].substr(0,2)), 90 + i * 100 , 70 + j * 80, 80, 40, !levelInformation[asLevel[i][j]][3] == '.');
        }
    }


}