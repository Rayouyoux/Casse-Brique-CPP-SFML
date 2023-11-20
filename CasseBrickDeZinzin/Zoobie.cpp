#include "Zoobie.h"

#include "ZoobiesType.h";
#include "GameManager.h";


Zoobie::Zoobie(float fHP, ZoobiesType* oType, float fX, float fY, float fWidth, float fHeight) : 
		 PhysicalGameObject(fX, fY, fWidth, fHeight) {
	m_fHP = fHP;
	m_oType = oType;
	m_oIteratorZoobie = GameManager::AddZoobie(this);
	m_oIteratorMove = GameManager::AddMovingGameObject(this);
}

//void Zoobies::Die() {
//
//}

void Zoobie::Attack(PhysicalGameObject* oGameObject) {
	//oGameObject->TakeDamage();
}

void Zoobie::TakeDamage(float fDamage) {
	m_fHP -= fDamage;
	if (m_fHP <= 0) {
		GameManager::AddDestroyObject(this);
	}
}

void Zoobie::onCollisionEnter(PhysicalGameObject* oGameObject) {
	if (oGameObject != nullptr) {
		if (typeid(*oGameObject).name() == "Turret") {
			Attack(oGameObject);
		}
		else if (typeid(*oGameObject).name() == "Projectile") {
			//TakeDamage();
		}
	}
	else {
		//Lose
	}
}

void Zoobie::onCollisionStay(PhysicalGameObject* oGameObject) {
	onCollisionEnter(oGameObject);
}

void Zoobie::onCollisionExit(PhysicalGameObject* oGameObject) {

}

Zoobie::~Zoobie() {
	GameManager::RemoveMovingGameObject(m_oIteratorMove);
	GameManager::RemoveZoobie(m_oIteratorZoobie);
}