#pragma once

#include "PhysicalGameObject.h"
class GameManager;

class Ball : public PhysicalGameObject
{
public:

	Ball(float fX, float fY, float fRadius, Window* oWindow, GameManager* oGameManager);
	~Ball();

	void onCollisionEnter(int side) override;
	void onCollisionStay(int side) override;
	void onCollisionExit(int side) override;
};

