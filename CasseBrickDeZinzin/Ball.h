#pragma once

#include "PhysicalGameObject.h"
#include <list>

class GameManager;

class Ball : public PhysicalGameObject
{
public:

	std::list<GameObject*>::iterator m_oIteratorMove;

	Ball(float fX, float fY, float fRadius);
	virtual ~Ball();

	void onCollisionEnter(int side) override;
	void onCollisionStay(int side) override;
	void onCollisionExit(int side) override;
};

