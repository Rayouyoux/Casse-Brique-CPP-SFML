#pragma once

#include "gameObject.h"
class Window;
class Vector2i;
class Vector2f;
class GameManager;

#include <list>

class PhysicalGameObject : public GameObject
{
public:
	PhysicalGameObject(float fX, float fY, float fWidth, float fHeight);
	PhysicalGameObject(float fX, float fY, float fRadius);

	void handleCollision();
	void handleCollision(PhysicalGameObject* oGameObject);
	int sideCollision(PhysicalGameObject* oGameObject);

	virtual void onCollisionEnter(int side);
	virtual void onCollisionStay(int side);
	virtual void onCollisionExit(int side);
	virtual ~PhysicalGameObject();

	std::list<GameObject*> m_oObjectCollision;
	bool m_bWindowCollision;
	std::list<PhysicalGameObject*>::iterator m_oIterator;
};

