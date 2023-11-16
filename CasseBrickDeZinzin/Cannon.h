#pragma once

#include "maths.h"
#include "Ball.h"
#include "gameObject.h"
#include <SFML/Graphics.hpp>
class Window;


class Cannon : public GameObject
{
public:
	Cannon(float fX, float fY, float fWidth, float fHeight, Window* oWindow);
	void shoot(float fMouseX, float fMouseY, Window* oWindow, GameManager* oGameManager);
	void rotate(float fX, float fY);
	~Cannon();
};

