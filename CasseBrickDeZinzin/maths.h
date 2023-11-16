#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

namespace maths {

	bool IsPointInside(float i, float iMin, float iMax);
	void normalizeVector(sf::Vector2f* orientationVector);
	void bounceVector(sf::Vector2f* orientationVector, int side);
	sf::Vector2f getOrientationVector(float fAX, float fAY, float fBX, float fBY);
	/*float getAngle(sf::Vector2f* oVector1, sf::Vector2f* oVector2);
	float getLength(float fLength, float fAngle);*/
	float normVector(sf::Vector2f* oVector);
	void invertVector(sf::Vector2f* orientationVector);
	void getCoefficientLine(sf::Vector2f* oVector, float fX, float fY, float* fResult);
	float getVerticalIntersection(float fA, float fB, float fX);
	float getHorizontalIntersection(float fA, float fB, float fY);
	bool isPointOnSegment(float fAX, float fAY, float fBX, float fBY, float fX, float fY);
	float getLengthSegment(float fAX, float fAY, float fBX, float fBY);
}

