#pragma once

#include "gameObject.h"
class Window;
class Vector2i;
class Vector2f;

class PhysicalGameObject : public GameObject
{
public:
	PhysicalGameObject(float fX, float fY, float fWidth, float fHeight, sf::Vector2i* oOrientation, Window* oWindow);
	PhysicalGameObject(float fX, float fY, float fRadius, sf::Vector2i* oOrientation, Window* oWindow);
	void move(float fDeltaTime, float fspeed);
	void handleCollision(sf::RenderWindow* oWindow);
	void handleCollision(GameObject* oGameObject);
	int sideCollision(GameObject* oGameObjec, float fX, float fY);
	virtual void onCollisionEnter(int side);
	virtual void onCollisionStay(int side);
	virtual void onCollisionExit(int side);
	~PhysicalGameObject();

	sf::Vector2f m_oOrientation;
	std::vector<GameObject*> m_oObjectCollision;
	bool m_bWindowCollision;
};

