#include "maths.h"

namespace maths {

	bool IsPointInside(int i, int iMin, int iMax) {
		return i >= iMin && i <= iMax;
	}

}