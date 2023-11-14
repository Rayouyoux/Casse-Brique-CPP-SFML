#pragma once

#include "PhysicalGameObject.h"

class Brick : public PhysicalGameObject
{
public:

	int m_iLife;

	Brick(int iLife, float fX, float fY, float fWidth, float fHeight, Window* oWindow);
	~Brick();

	void takeDamage();
	void setColor();
	void onCollisionEnter(int side) override;
	void onCollisionStay(int side) override;
	void onCollisionExit(int side) override;
};

