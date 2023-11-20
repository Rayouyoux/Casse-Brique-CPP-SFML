#include "Location.h"

#include "GameManager.h"

Location::Location(float fHP, TurretType* oType, float fX, float fY, float fWidth, float fHeight) :
	PhysicalGameObject(fX, fY, fWidth, fHeight) {
	m_fHP = fHP;
	m_oType = oType;
	m_oIteratorLocation = GameManager::AddLocation(this);
	m_oIteratorMove = GameManager::AddMovingGameObject(this);
}

void Location::Buy() {

}

void Location::Sell() {

}

void Location::onClick() {

}

void Location::onCollisionEnter(PhysicalGameObject* oGameObject) {

}

void Location::onCollisionStay(PhysicalGameObject* oGameObject) {

}

void Location::onCollisionExit(PhysicalGameObject* oGameObject) {

}

Location::~Location() {
	GameManager::RemoveMovingGameObject(m_oIteratorMove);
	GameManager::RemoveLocation(m_oIteratorLocation);
}