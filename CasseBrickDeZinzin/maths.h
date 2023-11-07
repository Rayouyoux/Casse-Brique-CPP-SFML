#pragma once
#include <iostream>
#include <vector>

namespace maths {

	bool IsPointInside(float i, float iMin, float iMax);
	void normalizeVector(std::vector<float> orientationVector);
	float getComplementaryAngle(float angle);
	void bounceVector(std::vector<float> orientationVector, int side, float angle);
}

