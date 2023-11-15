#include "maths.h"
#include <cmath>

namespace maths {

	bool IsPointInside(float f, float fMin, float fMax) {
		if (fMin > fMax)
		{
			float fSwap = fMin;
			fMin = fMax;
			fMax = fSwap;
		}

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
		fResult[0] = oVector->y / oVector->x;
		fResult[1] = ((-oVector->y * fX) / oVector->x) + fY;
	}

	float getVerticalIntersection(float fA, float fB, float fX) {
		return fA * fX + fB;
	}

	float getHorizontalIntersection(float fA, float fB, float fY) {
		return (fY - fB) / fA;
	}

	bool isPointOnSegment(float fAX, float fAY, float fBX, float fBY, float fX, float fY) {
		//std::cout << "A : x :" << fAX << " y : " << fAY << std::endl;
		//std::cout << "I : x :" << fX << " y : " << fY << std::endl;
		//std::cout << "B : x :" << fBX << " y : " << fBY << std::endl << std::endl;
		return IsPointInside(fX, fAX, fBX) && IsPointInside(fY, fAY, fBY);
	}

	float getLengthSegment(float fAX, float fAY, float fBX, float fBY) {
		sf::Vector2f* oVector = new sf::Vector2f(fBX - fAX, fBY - fAY);
		/*std::cout << "B : x :" << fBX << " y : " << fBY << std::endl << std::endl;*/
		return normVector(oVector);
	}
}
