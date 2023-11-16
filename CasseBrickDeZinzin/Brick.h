#pragma once

#include "PhysicalGameObject.h"
class GameManager;

class Brick : public PhysicalGameObject
{
public:

	int m_iLife;

	Brick(int iLife, float fX, float fY, float fWidth, float fHeight, Window* oWindow, GameManager* oGameManager);
	~Brick();

	void takeDamage();
	void setColor();
	void onCollisionEnter(int side) override;
	void onCollisionStay(int side) override;
	void onCollisionExit(int side) override;
};

