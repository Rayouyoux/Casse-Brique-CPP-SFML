#include "PhysicalGameObject.h"
#include "gameObject.h"
#include "maths.h"
#include "window.h"
#include "GameManager.h"
#include <SFML/Graphics.hpp>


PhysicalGameObject::PhysicalGameObject(float fX, float fY, float fWidth, float fHeight) : 
					GameObject (fX, fY, fWidth, fHeight) {
	m_bWindowCollision = false;
	m_oIterator = GameManager::AddPhysicalGameObject(this);
}

PhysicalGameObject::PhysicalGameObject(float fX, float fY, float fRadius) :
	GameObject(fX, fY, fRadius) {
	m_bWindowCollision = false;
	m_oIterator = GameManager::AddPhysicalGameObject(this);
}

void PhysicalGameObject::handleCollision(PhysicalGameObject* oGameObject) {
	bool bCollisionX;
	bool bCollisionY;

	if (m_fWidth <= oGameObject->m_fWidth) {
		bCollisionX = maths::IsPointInside(m_fX, oGameObject->m_fX, oGameObject->m_fX + oGameObject->m_fWidth) || 
			maths::IsPointInside(m_fX + m_fWidth, oGameObject->m_fX, oGameObject->m_fX + oGameObject->m_fWidth);
			
	}
	else {
		bCollisionX = maths::IsPointInside(oGameObject->m_fX, m_fX, m_fX + m_fWidth) ||
			maths::IsPointInside(oGameObject->m_fX + oGameObject->m_fWidth, m_fX, m_fX + m_fWidth);
	}

	if (m_fHeight <= oGameObject->m_fHeight) {
		bCollisionY = maths::IsPointInside(m_fY, oGameObject->m_fY, oGameObject->m_fY + oGameObject->m_fHeight) || 
			maths::IsPointInside(m_fY + m_fHeight, oGameObject->m_fY, oGameObject->m_fY + oGameObject->m_fHeight);
		 	
	}
	else {
		bCollisionY = maths::IsPointInside(oGameObject->m_fY, m_fY, m_fY + m_fHeight) ||
			maths::IsPointInside(oGameObject->m_fY + oGameObject->m_fHeight, m_fY, m_fY + m_fHeight);
	}

	auto iIndex = std::find(m_oObjectCollision.begin(), m_oObjectCollision.end(), oGameObject);
	if (bCollisionX && bCollisionY) {
		if (iIndex == m_oObjectCollision.end()) {
			onCollisionEnter(oGameObject);
			oGameObject->onCollisionEnter(this);
			m_oObjectCollision.push_back(oGameObject);
		}
		else {
			onCollisionStay(oGameObject);
			oGameObject->onCollisionStay(this);
		}
	}
	else
	{
		if (iIndex != m_oObjectCollision.end()) {
			onCollisionExit(oGameObject);
			oGameObject->onCollisionExit(this);
			m_oObjectCollision.erase(iIndex);
		}
	}
}

void PhysicalGameObject::handleCollision() {
	int sideCollsion = 0;
	if (m_fX < 0 || m_fX + m_fWidth > Window::m_oWindow->getSize().x) {
		sideCollsion = 1;
	}
	else if (m_fY < 0) {
		sideCollsion = 2;
	}
	else if (m_fY > Window::m_oWindow->getSize().y) {
		sideCollsion = 3;
	}
	if (sideCollsion != 0) {
		if (!m_bWindowCollision) {
			onCollisionEnter();
			m_bWindowCollision = true;
		}
		else {
			onCollisionStay();
		}
	}
	else
	{
		if (m_bWindowCollision) {
			onCollisionExit();
			m_bWindowCollision = false;
		}
	}
}

void PhysicalGameObject::onCollisionEnter(PhysicalGameObject* oGameObject) {

}

void PhysicalGameObject::onCollisionStay(PhysicalGameObject* oGameObject) {

}

void PhysicalGameObject::onCollisionExit(PhysicalGameObject* oGameObject) {

}

PhysicalGameObject::~PhysicalGameObject() {
	GameManager::RemovePhysicalGameObject(m_oIterator);
}