#include "PhysicalGameObject.h"
#include "gameObject.h"
#include "maths.h"
#include "window.h"
#include <SFML/Graphics.hpp>


PhysicalGameObject::PhysicalGameObject(float fX, float fY, float fWidth, float fHeight, sf::Vector2i* oOrientation, Window* oWindow) : 
					GameObject (fX, fY, fWidth, fHeight, oWindow) {
	m_oOrientation = maths::getOrientationVector(oOrientation, fX, fY);
	m_bWindowCollision = false;
}

PhysicalGameObject::PhysicalGameObject(float fX, float fY, float fRadius, sf::Vector2i* oOrientation, Window* oWindow) :
	GameObject(fX, fY, fRadius, oWindow) {
	m_oOrientation = maths::getOrientationVector(oOrientation, fX, fY);
	m_bWindowCollision = false;
}

void PhysicalGameObject::move(float fDeltaTime, float fspeed) {
	float fX = m_fX + m_oOrientation.x * fDeltaTime * fspeed;
	float fY = m_fY + m_oOrientation.y * fDeltaTime * fspeed;
	setPosition(fX, fY);
}

void PhysicalGameObject::handleCollision(GameObject* oGameObject) {
	bool bCollisionX;
	bool bCollisionY;

	bool bCollisionA;
	bool bCollisionB;
	bool bCollisionC;
	bool bCollisionD;
	float fXCollision = 0.f;
	float fYCollision = 0.f;

	if (m_fWidth <= oGameObject->m_fWidth) {
		bCollisionA = maths::IsPointInside(m_fX, oGameObject->m_fX, oGameObject->m_fX + oGameObject->m_fWidth);
		bCollisionB = maths::IsPointInside(m_fX + m_fWidth, oGameObject->m_fX, oGameObject->m_fX + oGameObject->m_fWidth);
		if (bCollisionA) {
			fXCollision = m_fX;
		}
		else {
			fXCollision = m_fX + m_fWidth;
		}
		bCollisionX = bCollisionA || bCollisionB;
			
	}
	else {
		bCollisionX = maths::IsPointInside(oGameObject->m_fX, m_fX, m_fX + m_fWidth) ||
			maths::IsPointInside(oGameObject->m_fX + oGameObject->m_fWidth, m_fX, m_fX + m_fWidth);
	}

	if (m_fHeight <= oGameObject->m_fHeight) {
		bCollisionC = maths::IsPointInside(m_fY, oGameObject->m_fY, oGameObject->m_fY + oGameObject->m_fHeight);
		bCollisionD = maths::IsPointInside(m_fY + m_fHeight, oGameObject->m_fY, oGameObject->m_fY + oGameObject->m_fHeight);
		if (bCollisionC) {
			fYCollision = m_fY;
		}
		else {
			fYCollision = m_fY + m_fHeight;
		}
		bCollisionY = bCollisionC || bCollisionD;	
	}
	else {
		bCollisionY = maths::IsPointInside(oGameObject->m_fY, m_fY, m_fY + m_fHeight) ||
			maths::IsPointInside(oGameObject->m_fY + oGameObject->m_fHeight, m_fY, m_fY + m_fHeight);
	}

	auto iIndex = std::find(m_oObjectCollision.begin(), m_oObjectCollision.end(), oGameObject);
	if (bCollisionX && bCollisionY) {
		if (iIndex == m_oObjectCollision.end()) {
			onCollisionEnter(sideCollision(oGameObject, fXCollision, fYCollision));
			//oGameObject->onCollisionEnter(sideCollision(oGameObject));
			m_oObjectCollision.push_back(oGameObject);
		}
		else {
			//onCollisionStay(sideCollision(oGameObject));
		}
	}
	else
	{
		if (iIndex != m_oObjectCollision.end()) {
			/*onCollisionExit(sideCollision(oGameObject));*/
			m_oObjectCollision.erase(iIndex);
		}
	}
}


int PhysicalGameObject::sideCollision(GameObject* oGameObjec, float fX, float fY) {
	float fLongerX = fX - oGameObjec->m_fX;
	sf::Vector2f* oVectorX = new sf::Vector2f(-fLongerX, 0);
	float fAngleX = maths::getAngle(oVectorX, &m_oOrientation);

	float fLongerY = fY - oGameObjec->m_fY;
	sf::Vector2f* oVectorY = new sf::Vector2f(0, -fLongerY);
	float fAngleY = maths::getAngle(oVectorY, &m_oOrientation);

	std::cout << fAngleX << std::endl << fAngleY << std::endl;
	if (fAngleX < fAngleY) {
		float fLongerReturn = maths::getLonger(oVectorX, fAngleX);
		setPosition(m_fX - fLongerReturn, m_fY);
	}
	else {
		float fLongerReturn = maths::getLonger(oVectorY, fAngleY);
		setPosition(m_fX, m_fY + fLongerReturn);
	}

	return 0;
}

void PhysicalGameObject::handleCollision(sf::RenderWindow* oWindow) {
	int sideCollsion = 0;
	if (m_fX < 0 || m_fX + m_fWidth > oWindow->getSize().x) {
		sideCollsion = 1;
	}
	else if (m_fY < 0 || m_fY + m_fHeight > oWindow->getSize().y) {
		sideCollsion = 2;
	}
	if (sideCollsion != 0) {
		if (!m_bWindowCollision) {
			onCollisionEnter(sideCollsion);
		}
		else {
			onCollisionStay(sideCollsion);
		}
	}
	else
	{
		if (m_bWindowCollision) {
			onCollisionExit(sideCollsion);
		}
	}
}

void PhysicalGameObject::onCollisionEnter(int side) {
	/*maths::bounceVector(&m_oOrientation, side);*/
}

void PhysicalGameObject::onCollisionStay(int side) {

}

void PhysicalGameObject::onCollisionExit(int side) {

}

PhysicalGameObject::~PhysicalGameObject() {

}