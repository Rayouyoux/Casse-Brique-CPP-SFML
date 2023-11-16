#pragma once

#include "gameObject.h"
class Window;
class Vector2i;
class Vector2f;
class GameManager;

class PhysicalGameObject : public GameObject
{
public:
	PhysicalGameObject(float fX, float fY, float fWidth, float fHeight, Window* oWindow, GameManager* oGameManager);
	PhysicalGameObject(float fX, float fY, float fRadius, Window* oWindow, GameManager* oGameManager);

	void handleCollision(sf::RenderWindow* oWindow);
	void handleCollision(PhysicalGameObject* oGameObject);
	int sideCollision(PhysicalGameObject* oGameObject);

	virtual void onCollisionEnter(int side);
	virtual void onCollisionStay(int side);
	virtual void onCollisionExit(int side);
	~PhysicalGameObject();

	std::vector<GameObject*> m_oObjectCollision;
	bool m_bWindowCollision;
};

