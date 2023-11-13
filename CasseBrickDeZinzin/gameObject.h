#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
class Window;

class GameObject {

public:

	GameObject(float iX, float iY, float iWidht, float iHeight, Window* oWindow);
	GameObject(float iX, float iY, float iRadius, Window* oWindow);
	/*sf::Vector2i* oOrientation*/

	/*void handleCollision(GameObject* oGameObject);
	void handleCollision(sf::RenderWindow* oWindow);
	int sideCollision(GameObject* oGameObjec, float fX, float fY);*/
	/*void move(float fDeltaTime, float fspeed);*/
	/*void rotate(sf::Vector2i* oMousePosition);*/
	/*void onCollisionEnter(int side);
	void onCollisionStay(int side);
	void onCollisionExit(int side);*/
	void setPosition(float fX, float fY);
	void setRotation(float fAngle);

	float m_fX;
	float m_fY;
	float m_fWidth;
	float m_fHeight;
	sf::Shape* m_oGraphic;
	/*std::vector<GameObject*> m_oObjectCollision;*/
	/*sf::Vector2f m_oOrientation;*/

	~GameObject();
};

