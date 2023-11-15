#pragma once

#include "maths.h"
#include "gameObject.h"
#include <SFML/Graphics.hpp>
class Window;
class Ball;


class Cannon : public GameObject
{
public:
	Cannon(float fX, float fY, float fWidth, float fHeight, Window* oWindow);

	Ball shoot(sf::Vector2f* orientation,);

	sf::Vector2f getOrientationVector(sf::Vector2i* oMousePosition, float fX, float fY);

	~Cannon();

	void rotate(sf::Vector2i* oMousePosition);
};

