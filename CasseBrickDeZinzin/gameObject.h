#pragma once

#include <SFML/Graphics.hpp>

class GameObject {

public:

	GameObject(float iX, float iY, float iWidht, float iHeight, sf::Vector2i* oOrientation);
	GameObject(float iX, float iY, float iRadius, sf::Vector2i* oOrientation);

	void handleCollision(GameObject* oGameObject);
	void handleCollision(sf::RenderWindow* oWindow);
	int sideCollision(GameObject* oGameObject);
	void move(float fDeltaTime, float fspeed);
	void rotate(sf::Vector2i* oMousePosition);
	void onCollisionEnter(int side);
	void onCollisionStay(int side);
	void onCollisionExit(int side);
	void setPosition(float fX, float fY);

	float m_fX;
	float m_fY;
	float m_fWidth;
	float m_fHeight;
	sf::Shape* m_oGraphic;
	GameObject* m_oObjectCollision;
	sf::Vector2f m_oOrientation;

	~GameObject();
};

