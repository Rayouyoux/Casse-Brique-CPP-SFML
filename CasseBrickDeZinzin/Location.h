#pragma once

#include "PhysicalGameObject.h"

class TurretType;
class GameObject;

class Location : PhysicalGameObject
{
public :

	TurretType* m_oType;
	float m_fHP;
	std::list<Location*>::iterator m_oIteratorLocation;
	std::list<GameObject*>::iterator m_oIteratorMove;

	Location(float fHP, TurretType* oType, float fX, float fY, float fWidth, float fHeight);
	virtual ~Location();

	void Buy();
	void Sell();
	void onClick();
	void onCollisionEnter(PhysicalGameObject* oGameObject = nullptr) override;
	void onCollisionStay(PhysicalGameObject* oGameObject = nullptr) override;
	void onCollisionExit(PhysicalGameObject* oGameObject = nullptr) override;
};

