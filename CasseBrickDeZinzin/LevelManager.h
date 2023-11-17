#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Brick.h"

class LevelManager {

public :

	std::fstream m_fLevel;

	std::vector<std::string> fileToText(const char* sFileName);
	void createLevel(std::vector<std::string> asLevel);

};

// C:\Users\relkotob\Desktop