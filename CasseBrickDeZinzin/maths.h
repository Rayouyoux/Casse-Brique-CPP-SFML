#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

namespace maths {

	bool IsPointInside(float i, float iMin, float iMax);
	void normalizeVector(sf::Vector2f* orientationVector);
	void bounceVector(sf::Vector2f* orientationVector, int side);
	sf::Vector2f getOrientationVector(sf::Vector2i* oMousePosition, float fX, float fY);
	float getAngle(sf::Vector2f* oVector1, sf::Vector2f* oVector2);
	float getLength(float fLength, float fAngle);
	float normVector(sf::Vector2f* oVector);
	void invertVector(sf::Vector2f* orientationVector);
}

