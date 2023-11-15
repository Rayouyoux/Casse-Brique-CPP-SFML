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

	void shoot(sf::Vector2f* orientation, Window* oWindow);

	sf::Vector2f getOrientationVector(sf::Vector2i* oMousePosition, float fX, float fY);

	~Cannon();

	void rotate(sf::Vector2i* oMousePosition);
};

