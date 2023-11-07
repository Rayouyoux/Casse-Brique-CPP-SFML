#include "maths.h"
#include <cmath>

namespace maths {

	bool IsPointInside(float i, float iMin, float iMax) {
		return i >= iMin && i <= iMax;
	}

	void normalizeVector(std::vector<float> orientationVector) {
		float vectorNorm = sqrt(pow(orientationVector[0],2)+pow(orientationVector[1], 2));
		orientationVector[0] = orientationVector[0] / vectorNorm;
		orientationVector[1] = orientationVector[1] / vectorNorm;
	}

	float getComplementaryAngle(float angle) {
		return 90 - angle;
	}

	void bounceVector(std::vector<float> orientationVector, int side, float angle) {

	}

}
