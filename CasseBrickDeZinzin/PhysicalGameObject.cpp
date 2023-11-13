#include "PhysicalGameObject.h"
#include "gameObject.h"
#include "maths.h"
#include "window.h"
#include <SFML/Graphics.hpp>


PhysicalGameObject::PhysicalGameObject(float fX, float fY, float fWidth, float fHeight, Window* oWindow) : 
					GameObject (fX, fY, fWidth, fHeight, oWindow) {
	m_bWindowCollision = false;
}

PhysicalGameObject::PhysicalGameObject(float fX, float fY, float fRadius, Window* oWindow) :
	GameObject(fX, fY, fRadius, oWindow) {
	m_bWindowCollision = false;
}

void PhysicalGameObject::handleCollision(GameObject* oGameObject) {
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
			onCollisionEnter(sideCollision(oGameObject));
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


int PhysicalGameObject::sideCollision(GameObject* oGameObject) {
	sf::Vector2f* oInverseVector = new sf::Vector2f(0, 0);
	float fdistance;
	if (m_fHeight < oGameObject->m_fHeight) {
		oInverseVector->x = m_oOrientation.x;
		oInverseVector->y = m_oOrientation.y;
		maths::invertVector(oInverseVector);
		std::cout << "Inverse Vector x :" << oInverseVector->x << " y :" << oInverseVector->y << std::endl;
		fdistance = m_oOrientation.y < 0 ? oGameObject->m_fY + oGameObject->m_fHeight - m_fY : 
											m_fY + m_fHeight - oGameObject->m_fY;
		std::cout <<"Distance : " << fdistance << std::endl;
	}
	else {
		oInverseVector->x = oGameObject->m_oOrientation.x;
		oInverseVector->y = oGameObject->m_oOrientation.y;
		maths::invertVector(oInverseVector);
		fdistance = oGameObject->m_oOrientation.y < 0 ? m_fY + m_fHeight - oGameObject->m_fY : 
														oGameObject->m_fY + oGameObject->m_fHeight - m_fY;
	}
	sf::Vector2f* oVector = new sf::Vector2f(0, fdistance);
	if (m_oOrientation.y > 0) {
		oVector->y = -fdistance;
	}
	std::cout << "x :" << oVector->x << " y :" << oVector->y << std::endl;
	float fAngle = maths::getAngle(oInverseVector, oVector);
	std::cout << "Angle : " << fAngle << std::endl;
	float fLength = maths::getLength(fdistance, fAngle);
	std::cout << "Length : " << fLength << std::endl;
	oInverseVector->x *= fLength;
	oInverseVector->y *= fLength;
	std::cout << "Inverse Vector Before Pos x :" << oInverseVector->x << " y :" << oInverseVector->y << std::endl;
	if (m_fHeight < oGameObject->m_fHeight) {
		setPosition(m_fX + oInverseVector->x, m_fY + oInverseVector->y);
	}
	else {
		setPosition(oGameObject->m_fX + oInverseVector->x, oGameObject->m_fY + oInverseVector->y);
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