#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

namespace maths {

	bool IsPointInside(float i, float iMin, float iMax);
	void normalizeVector(sf::Vector2f orientationVector);
	void bounceVector(sf::Vector2f orientationVector, int side);
	sf::Vector2f getOrientationVector(sf::Vector2i& oMousePosition, float fX, float fY);
}

