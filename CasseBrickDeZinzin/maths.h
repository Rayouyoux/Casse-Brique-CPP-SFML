#pragma once

#include <SFML/Graphics.hpp>

namespace maths {

	bool IsPointInside(float i, float iMin, float iMax);
	void normalizeVector(sf::Vector2f* orientationVector);
	float normVector(sf::Vector2f* oVector);
}

