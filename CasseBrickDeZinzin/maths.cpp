#include "maths.h"
#include <cmath>

namespace maths {

	bool IsPointInside(float i, float iMin, float iMax) {
		return i >= iMin && i <= iMax;
	}

	void normalizeVector(sf::Vector2f* orientationVector) {
		float vectorNorm = sqrt(pow(orientationVector->x,2)+pow(orientationVector->y, 2));
		orientationVector->x = orientationVector->x / vectorNorm;
		orientationVector->y = orientationVector->y / vectorNorm;
	}

	void bounceVector(sf::Vector2f* orientationVector, int side) {
		side == 1 ? orientationVector->x = -orientationVector->x : orientationVector->y = -orientationVector->y;
	}

	sf::Vector2f getOrientationVector(sf::Vector2i* oMousePosition, float fX, float fY) {
		sf::Vector2f orientationVector;
		orientationVector.x = oMousePosition->x - fX;
		orientationVector.y = oMousePosition->y - fY;
		normalizeVector(&orientationVector);
		return orientationVector;
	}

}
