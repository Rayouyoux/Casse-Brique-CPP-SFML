#pragma once

#include <SFML/Graphics.hpp>

class GameObject {

public:

	GameObject(float iX, float iY, float iWidht, float iHeight);
	GameObject(float iX, float iY, float iRadius);

	~GameObject();

	bool isCollision(GameObject* oGameObject);
	void move(float fDeltaTime, sf::Vector2i direction);
	void rotate(sf::Vector2i* oMousePosition);

	float m_fX;
	float m_fY;
	float m_fWidth;
	float m_fHeight;
	float m_fRadius;
	sf::Shape* m_oGraphic;

};

