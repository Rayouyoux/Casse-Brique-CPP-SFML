#pragma once

#include "PhysicalGameObject.h";

class ZoobiesType;
class GameObject;

class Zoobie : PhysicalGameObject
{
public :

	ZoobiesType* m_oType;
	float m_fHP; 
	std::list<Zoobie*>::iterator m_oIteratorZoobie;
	std::list<GameObject*>::iterator m_oIteratorMove;

	Zoobie(float fHP, ZoobiesType* oType, float fX, float fY, float fWidth, float fHeight);
	virtual ~Zoobie();

	/*void Die();*/
	void Attack(PhysicalGameObject* oGameObject);
	void TakeDamage(float fDamage);
	void onCollisionEnter(PhysicalGameObject* oGameObject = nullptr) override;
	void onCollisionStay(PhysicalGameObject* oGameObject = nullptr) override;
	void onCollisionExit(PhysicalGameObject* oGameObject = nullptr) override;
};

