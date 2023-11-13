#pragma once

#include "gameObject.h"
#include <SFML/Graphics.hpp>
class Window;


class Cannon : public GameObject
{
public:
	Cannon(float fX, float fY, float fWidth, float fHeight, Window* oWindow);
	~Cannon();

	void rotate(sf::Vector2i* oMousePosition);
};

