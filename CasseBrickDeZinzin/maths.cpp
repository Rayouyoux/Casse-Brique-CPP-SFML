#include "maths.h"

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
}
