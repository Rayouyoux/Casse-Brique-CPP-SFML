#pragma once

#include "PhysicalGameObject.h"

class Ball : public PhysicalGameObject
{
public:
	Ball(float fX, float fY, float fRadius, Window* oWindow);
	~Ball();

	void onCollisionEnter(int side) override;
	void onCollisionStay(int side) override;
	void onCollisionExit(int side) override;
};

