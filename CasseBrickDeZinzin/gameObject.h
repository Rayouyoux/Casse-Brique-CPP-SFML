#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
class Window;

class GameObject {

public:

	GameObject(float fX, float fY, float fWidth, float fHeight, Window* oWindow);
	GameObject(float iX, float iY, float iRadius, Window* oWindow);

	void move(float fDeltaTime, float fspeed);
	void setPosition(float fX, float fY);
	void setOrigin(float fX, float fY);
	void setRotation(float fAngle);
	void setColor(const sf::Color& oColor);
	void setDebugPosition(float fX, float fY);
	void draw(Window* oWindow);

	float m_fX;
	float m_fY;
	float m_fWidth;
	float m_fHeight;
	sf::Shape* m_oGraphic;
	sf::Vector2f m_oOrientation;
	sf::Shape* m_oDebugPoint;
	bool m_bDrawDebug;

	~GameObject();
};

