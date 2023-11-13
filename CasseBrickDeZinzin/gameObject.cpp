#include "gameObject.h"
#include "maths.h"
#include "window.h"
#include <iostream>

GameObject::GameObject(float fX, float fY, float fWidth, float fHeight, Window* oWindow) {
	m_fX = fX;
	m_fY = fY;
	m_fWidth = fWidth;
	m_fHeight = fHeight;
	m_oGraphic = new sf::RectangleShape(sf::Vector2f(fWidth, fHeight));
	m_oGraphic->setPosition(m_fX, m_fY);
	m_oOrientation = sf::Vector2f(1, 1);
	maths::normalizeVector(&m_oOrientation);
	std::cout << "x :" << m_oOrientation.x << " y :" << m_oOrientation.y << std::endl;
	oWindow->m_voWindowObjects.push_back(this);
}

GameObject::GameObject(float fX, float fY, float fRadius, Window* oWindow) {
	m_fX = fX;
	m_fY = fY;
	m_fWidth = fRadius * 2;
	m_fHeight = fRadius * 2;
	m_oGraphic = new sf::CircleShape(fRadius);
	m_oGraphic->setPosition(m_fX, m_fY);
	m_oOrientation = sf::Vector2f(1, 1);
	maths::normalizeVector(&m_oOrientation);
	oWindow->m_voWindowObjects.push_back(this);
}

//void GameObject::handleCollision(GameObject* oGameObject) {
//    bool bCollisionX;
//    bool bCollisionY;
//
//	if (m_fWidth < oGameObject->m_fWidth) {
//		bCollisionX = maths::IsPointInside(m_fX, oGameObject->m_fX, oGameObject->m_fX + oGameObject->m_fWidth) ||
//			maths::IsPointInside(m_fX + m_fWidth, oGameObject->m_fX, oGameObject->m_fX + oGameObject->m_fWidth);
//	}
//    else {
//        bCollisionX = maths::IsPointInside(oGameObject->m_fX, m_fX, m_fX + m_fWidth) ||
//            maths::IsPointInside(oGameObject->m_fX + oGameObject->m_fWidth, m_fX, m_fX + m_fWidth);
//    }
//
//    if (m_fHeight < oGameObject->m_fHeight) {
//        bCollisionY = maths::IsPointInside(m_fY, oGameObject->m_fY, oGameObject->m_fY + oGameObject->m_fHeight) ||
//            maths::IsPointInside(m_fY + m_fHeight, oGameObject->m_fY, oGameObject->m_fY + oGameObject->m_fHeight);
//    }
//    else {
//        bCollisionY = maths::IsPointInside(oGameObject->m_fY, m_fY, m_fY + m_fHeight) ||
//            maths::IsPointInside(oGameObject->m_fY + oGameObject->m_fHeight, m_fY, m_fY + m_fHeight);
//    }
//
//	auto iIndex = std::find(m_oObjectCollision.begin(), m_oObjectCollision.end(), oGameObject);
//	if (bCollisionX && bCollisionY) {
//		if (iIndex == m_oObjectCollision.end()) {
//			onCollisionEnter(sideCollision(oGameObject, m_fX + m_fWidth, m_fY));
//			//oGameObject->onCollisionEnter(sideCollision(oGameObject));
//			m_oObjectCollision.push_back(oGameObject);
//		}
//		else {
//			//onCollisionStay(sideCollision(oGameObject));
//		}
//	}
//	else 
//	{
//		if (iIndex != m_oObjectCollision.end()) {
//			/*onCollisionExit(sideCollision(oGameObject));*/
//			m_oObjectCollision.erase(iIndex);
//		}
//	}
//}
//
//
//int GameObject::sideCollision(GameObject* oGameObjec, float fX, float fY) {
//	float fLongerX = fX - oGameObjec->m_fX;
//	sf::Vector2f* oVectorX = new sf::Vector2f(-fLongerX, 0);
//	float fLongerY = fY - oGameObjec->m_fY;
//	sf::Vector2f* oVectorY = new sf::Vector2f(-fLongerY, 0);
//	float fAngleX = maths::getAngle(oVectorX, &m_oOrientation);
//	float fAngleY = maths::getAngle(oVectorY, &m_oOrientation);
//	std::cout << fAngleX << std::endl << fAngleY << std::endl;
//	if (fAngleX < fAngleY) {
//		float fLongerReturn = maths::getLonger(oVectorX, fAngleX);
//		setPosition(m_fX - fLongerReturn, m_fY);
//	}
//	else {
//		/*float fLongerReturn = maths::getLonger(oVectorY, fAngleY);
//		setPosition(m_fX, m_fY - fLongerReturn);*/
//	}
//	
//	return 0;
//}
//
//void GameObject::handleCollision(sf::RenderWindow* oWindow) {
//	int sideCollsion = 0;
//	if (m_fX < 0 || m_fX + m_fWidth > oWindow->getSize().x) {
//		sideCollsion = 1;
//	}
//	else if (m_fY < 0 || m_fY + m_fHeight > oWindow->getSize().y) {
//		sideCollsion = 2;
//	}
//	auto iIndex = std::find(m_oObjectCollision.begin(), m_oObjectCollision.end(), oWindow);
//	if (sideCollsion != 0) {
//		if (iIndex == m_oObjectCollision.end()) {
//			onCollisionEnter(sideCollsion);
//			/*m_oObjectCollision.push_back(oWindow);*/
//		}
//		else {
//			onCollisionStay(sideCollsion);
//		}
//	}
//	else
//	{
//		if (iIndex != m_oObjectCollision.end()){
//			onCollisionExit(sideCollsion);
//			m_oObjectCollision.erase(iIndex);
//		}
//	}
//}

void GameObject::setPosition(float fX, float fY) {
	m_fX = fX;
	m_fY = fY;
	m_oGraphic->setPosition(m_fX, m_fY);
}


void GameObject::move(float fDeltaTime, float fspeed) {
	float fX = m_fX + m_oOrientation.x * fDeltaTime * fspeed;
	float fY = m_fY + m_oOrientation.y * fDeltaTime * fspeed;
	setPosition(fX, fY);
}

void GameObject::setRotation(float fAngle) {
	m_oGraphic->setRotation(fAngle);
}

//void GameObject::rotate(sf::Vector2i* oMousePosition) {
//	if (oMousePosition->y < m_fY) {
//		setRotation(-atan2(oMousePosition->x - m_fX, oMousePosition->y - m_fY) * 180 / 3.14159);
//	}
//}

//void GameObject::onCollisionEnter(int side) {
//	/*maths::bounceVector(&m_oOrientation, side);*/
//}
//
//void GameObject::onCollisionStay(int side) {
//
//}
//
//void GameObject::onCollisionExit(int side) {
//
//}

GameObject::~GameObject() {}