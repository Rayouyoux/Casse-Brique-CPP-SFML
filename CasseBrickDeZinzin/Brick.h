#pragma once

#include "PhysicalGameObject.h"

#include <list>

class GameManager;

class Brick : public PhysicalGameObject
{
public:

	int m_iLife;
	std::list<Brick*>::iterator m_oIteratorBrick;
	std::list<GameObject*>::iterator m_oIteratorMove;

	Brick(int iLife, float fX, float fY, float fWidth, float fHeight,  bool bCanMove);
	virtual ~Brick();

	void takeDamage();
	void setColor();
	void onCollisionEnter(int side) override;
	void onCollisionStay(int side) override;
	void onCollisionExit(int side) override;
};

