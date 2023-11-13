#pragma once

#include "gameObject.h"

class Ball : public GameObject
{

public:

	Ball(float fX, float fY, float fRadius, float fSpeed, sf::Vector2i* oOrientation);
	~Ball();

	float m_fRadius;
	float m_fSpeed;
	sf::Vector2f m_oOrientation;

};

