#include "maths.h"
#include <cmath>

namespace maths {

	bool IsPointInside(float i, float iMin, float iMax) {
		return i >= iMin && i <= iMax;
	}

	float normVector(sf::Vector2f* oVector) {
		return sqrt(pow(oVector->x, 2) + pow(oVector->y, 2));
	}

	void normalizeVector(sf::Vector2f* orientationVector) {
		float vectorNorm = normVector(orientationVector);
		orientationVector->x = orientationVector->x / vectorNorm;
		orientationVector->y = orientationVector->y / vectorNorm;
	}

	void bounceVector(sf::Vector2f* orientationVector, int side) {
		side == 1 ? orientationVector->x = -orientationVector->x : orientationVector->y = -orientationVector->y;
	}

	float getAngle(sf::Vector2f* oVector1, sf::Vector2f* oVector2) {
		float fScalar = oVector1->x * oVector2->x + oVector1->y * oVector2->y; 
		return acos(fScalar / (normVector(oVector1) * normVector(oVector2)))*180 / 3.14159;
	}

	float getLength(float fLength, float fAngle) {
		return fLength / cos(fAngle);
	}

	void invertVector(sf::Vector2f* orientationVector) {
		orientationVector->x = -orientationVector->x;
		orientationVector->y = -orientationVector->y;
	}

}
