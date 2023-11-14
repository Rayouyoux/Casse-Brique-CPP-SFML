#include "maths.h"
#include <cmath>

namespace maths {

	bool IsPointInside(float f, float fMin, float fMax) {
		return f >= fMin && f <= fMax;
	}

	float normVector(sf::Vector2f* oVector) {
		return sqrt(pow(oVector->x, 2) + pow(oVector->y, 2));
	}

	void normalizeVector(sf::Vector2f* oVector) {
		float vectorNorm = normVector(oVector);
		oVector->x = oVector->x / vectorNorm;
		oVector->y = oVector->y / vectorNorm;
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

	//float getAngle(sf::Vector2f* oVector1, sf::Vector2f* oVector2) {
	//	float fScalar = oVector1->x * oVector2->x + oVector1->y * oVector2->y; 
	//	return acos(fScalar / (normVector(oVector1) * normVector(oVector2)))*180 / 3.14159;
	//}

	//float getLength(float fLength, float fAngle) {
	//	return fLength / cos(fAngle);
	//}

	void invertVector(sf::Vector2f* orientationVector) {
		orientationVector->x = -orientationVector->x;
		orientationVector->y = -orientationVector->y;
	}

	void getCoefficientLine(sf::Vector2f* oVector, float fX, float fY, float* fResult) {
		fResult[0] = oVector->x == 0 ? 0 : oVector->y / oVector->x;
		fResult[1] = oVector->x == 0 ? fY : ((-oVector->y * fX) / oVector->x) + fY;
	}

	void getIntersectionLine(float fA1, float fB1, float fA2, float fB2, float* fResult) {
		/*fResult[1] = fA2 - fA1 == 0 ? 0 : (-fA1 * fB2 + fA2 * fB1) / (fA2 - fA1);
		fResult[0] = fA2 == 0 ? 0 : (fResult[1] - fB2) / fA2;*/
		fResult[0] = fA1 - fA2 == 0 ? 0 : (fB2 * fB1) / (fA1 - fA2);
		fResult[1] = fA1 * (fResult[0]) + fB1;
	}

	bool isPointOnSegment(float fAX, float fAY, float fBX, float fBY, float fX, float fY) {
		/*std::cout << "x :" << fX << " y : " << fY << std::endl;*/
		/*return (fAX <= fX <= fBX) && (fAY <= fY <= fBY);*/
		return IsPointInside(fX, fAX, fBX) && IsPointInside(fY, fAY, fBY);
	}

	float getLengthSegment(float fAX, float fAY, float fBX, float fBY) {
		sf::Vector2f* oVector = new sf::Vector2f(fBX - fAX, fBY - fAY);
		return normVector(oVector);
	}
}
