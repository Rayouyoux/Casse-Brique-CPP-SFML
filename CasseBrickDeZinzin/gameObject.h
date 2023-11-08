#pragma once

#include <SFML/Graphics.hpp>

class GameObject {

public:

	GameObject(float iX, float iY, float iWidht, float iHeight);
	GameObject(float iX, float iY, float iRadius);

	int isCollision(GameObject* oGameObject);
	int isCollision(sf::RenderWindow* oWindow);
	void move(float fDeltaTime, sf::Vector2f direction, float fspeed);
	void rotate(sf::Vector2i* oMousePosition);

	float m_fX;
	float m_fY;
	float m_fWidth;
	float m_fHeight;
	sf::Shape* m_oGraphic;

	~GameObject();
};

