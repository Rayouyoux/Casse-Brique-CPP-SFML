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

	virtual void onCollisionEnter(PhysicalGameObject* oGameObject = nullptr);
	virtual void onCollisionStay(PhysicalGameObject* oGameObject = nullptr);
	virtual void onCollisionExit(PhysicalGameObject* oGameObject = nullptr);
	virtual ~PhysicalGameObject();

	std::list<GameObject*> m_oObjectCollision;
	bool m_bWindowCollision;
	std::list<PhysicalGameObject*>::iterator m_oIterator;
};

