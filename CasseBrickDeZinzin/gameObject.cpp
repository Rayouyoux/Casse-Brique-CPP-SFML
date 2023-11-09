#include "gameObject.h"
#include "maths.h"
#include <iostream>

GameObject::GameObject(float fX, float fY, float fWidth, float fHeight, sf::Vector2i* oOrientation) {
	m_fX = fX;
	m_fY = fY;
	m_fWidth = fWidth;
	m_fHeight = fHeight;
	m_oGraphic = new sf::RectangleShape(sf::Vector2f(fWidth, fHeight));
	m_oGraphic->setPosition(m_fX, m_fY);
	m_oOrientation = maths::getOrientationVector(oOrientation, m_fX, m_fY);
	m_oObjectCollision = NULL;
}

GameObject::GameObject(float fX, float fY, float fRadius, sf::Vector2i* oOrientation) {
	m_fX = fX;
	m_fY = fY;
	m_fWidth = fRadius * 2;
	m_fHeight = fRadius * 2;
	m_oGraphic = new sf::CircleShape(fRadius);
	m_oGraphic->setPosition(m_fX, m_fY);
	m_oOrientation = maths::getOrientationVector(oOrientation, m_fX, m_fY);
	m_oObjectCollision = NULL;
}

void GameObject::handleCollision(GameObject* oGameObject) {
    bool bCollisionX;
    bool bCollisionY;

	if (m_fWidth < oGameObject->m_fWidth) {
		bCollisionX = maths::IsPointInside(m_fX, oGameObject->m_fX, oGameObject->m_fX + oGameObject->m_fWidth) ||
			maths::IsPointInside(m_fX + m_fWidth, oGameObject->m_fX, oGameObject->m_fX + oGameObject->m_fWidth);
	}
    else {
        bCollisionX = maths::IsPointInside(oGameObject->m_fX, m_fX, m_fX + m_fWidth) ||
            maths::IsPointInside(oGameObject->m_fX + oGameObject->m_fWidth, m_fX, m_fX + m_fWidth);
    }

    if (m_fHeight < oGameObject->m_fHeight) {
        bCollisionY = maths::IsPointInside(m_fY, oGameObject->m_fY, oGameObject->m_fY + oGameObject->m_fHeight) ||
            maths::IsPointInside(m_fY + m_fHeight, oGameObject->m_fY, oGameObject->m_fY + oGameObject->m_fHeight);
    }
    else {
        bCollisionY = maths::IsPointInside(oGameObject->m_fY, m_fY, m_fY + m_fHeight) ||
            maths::IsPointInside(oGameObject->m_fY + oGameObject->m_fHeight, m_fY, m_fY + m_fHeight);
    }

	if (bCollisionX && bCollisionY) {
		if (m_oObjectCollision == NULL) {
			onCollisionEnter(sideCollision(oGameObject));
			//oGameObject->onCollisionEnter(sideCollision(oGameObject));
			m_oObjectCollision = oGameObject;
		}
		else {
			onCollisionStay(sideCollision(oGameObject));
		}
	}
	else 
	{
		if (m_oObjectCollision != NULL) {
			onCollisionExit(sideCollision(oGameObject));
			m_oObjectCollision = NULL;
		}
	}
}


int GameObject::sideCollision(GameObject* oGameObject) {
	if (m_fX < oGameObject->m_fX || m_fX + m_fWidth > oGameObject->m_fX + oGameObject->m_fWidth) {
		std::cout << "1" << std::endl;
		return 1;
	}
	if (m_fY < oGameObject->m_fY || m_fY + m_fHeight > oGameObject->m_fY + oGameObject->m_fHeight) {
		std::cout << "2" << std::endl;
		return 2;
	}
	return 0;
}

void GameObject::handleCollision(sf::RenderWindow* oWindow) {
	int sideCollsion = 0;
	if (m_fX < 0 || m_fX + m_fWidth > oWindow->getSize().x) {
		sideCollsion = 1;
	}
	else if (m_fY < 0 || m_fY + m_fHeight > oWindow->getSize().y) {
		sideCollsion = 2;
	}
	if (sideCollsion != 0) {
		if (m_oObjectCollision == NULL) {
			onCollisionEnter(sideCollsion);
		}
		else {
			onCollisionStay(sideCollsion);
		}
	}
	else
	{
		if (m_oObjectCollision != NULL) {
			onCollisionExit(sideCollsion);
		}
	}
}

void GameObject::setPosition(float fX, float fY) {
	m_fX = fX;
	m_fY = fY;
	m_oGraphic->setPosition(m_fX, m_fY);
}


void GameObject::move(float fDeltaTime, float fspeed) {
	m_fX += m_oOrientation.x * fDeltaTime * fspeed;
	m_fY += m_oOrientation.y * fDeltaTime * fspeed;
	m_oGraphic->setPosition(m_fX, m_fY);
}

void GameObject::rotate(sf::Vector2i* oMousePosition) {
	m_oGraphic->setRotation(-atan2(oMousePosition->x - m_fX, oMousePosition->y - m_fY) * 180 / 3.14159);
}

void GameObject::onCollisionEnter(int side) {
	maths::bounceVector(&m_oOrientation, side);
}

void GameObject::onCollisionStay(int side) {

}

void GameObject::onCollisionExit(int side) {

}

GameObject::~GameObject() {}