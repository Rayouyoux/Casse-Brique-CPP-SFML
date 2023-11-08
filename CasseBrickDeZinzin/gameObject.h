#pragma once

#include <SFML/Graphics.hpp>

class GameObject {

public:

	GameObject(float iX, float iY, float iWidht, float iHeight);
	GameObject(float iX, float iY, float iRadius);

	bool isCollision(GameObject* oGameObject);
	bool isCollision(sf::RenderWindow* oWindow);
	void move(float fDeltaTime, sf::Vector2i direction, float fspeed);
	void rotate(sf::Vector2i* oMousePosition);

	float m_fX;
	float m_fY;
	float m_fWidth;
	float m_fHeight;
	sf::Shape* m_oGraphic;

	~GameObject();
};

