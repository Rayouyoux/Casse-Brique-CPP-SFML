#pragma once

#include <SFML/Graphics.hpp>
#include <list>

class Window;

class GameObject {

public:

	GameObject(float fX, float fY, float fWidth, float fHeight);
	GameObject(float iX, float iY, float iRadius);

	void move(float fDeltaTime, float fspeed);
	void setPosition(float fX, float fY);
	void setOrigin(float fX, float fY);
	void setRotation(float fAngle);
	/*void setColor(const sf::Color& oColor);
	void draw();*/
	void setDirection(sf::Vector2f* oDirection);

	float m_fX;
	float m_fY;
	float m_fWidth;
	float m_fHeight;
	sf::Shape* m_oGraphic;
	sf::Vector2f m_oOrientation;
	/*bool m_bMove;*/
	std::list<GameObject*>::iterator m_oIterator;

	virtual ~GameObject();
};

