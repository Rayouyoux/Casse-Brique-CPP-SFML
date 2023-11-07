#include "gameObject.h"
#include "maths.h"

#include <SFML/Graphics.hpp>

GameObject::GameObject(int iX, int iY, int iWidth, int iHeight) {
	m_iX = iX;
	m_iY = iY;
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	sf::RectangleShape m_oGraphic(sf::Vector2f(50.f, 50.f));
}

GameObject::GameObject(int iX, int iY, int iRadius) {
	m_iX = iX;
	m_iY = iY;
	m_iRadius = iRadius;
	sf::CircleShape m_oGraphic(100.f);
}

GameObject::~GameObject() {}

//void GameObject::setPosition(int iX, int iY) {
//	m_iX = iX;
//	m_iY = iY;
//}
//
//void GameObject::setSize(int iWidth, int iHeight) {
//	m_iWidth = iWidth;
//	m_iHeight = iHeight;
//}

bool GameObject::isCollision(GameObject* oGameObject) {
	if (m_iWidth < oGameObject->m_iWidth) {
		return maths::IsPointInside(m_iX, oGameObject->m_iX, oGameObject->m_iX + oGameObject->m_iWidth) ||
			   maths::IsPointInside(m_iX + m_iWidth, oGameObject->m_iX, oGameObject->m_iX + oGameObject->m_iWidth);
	}
	else {
		return maths::IsPointInside(oGameObject->m_iX, m_iX, m_iX + m_iWidth) ||
			   maths::IsPointInside(oGameObject->m_iX + oGameObject->m_iWidth, m_iX, m_iX + m_iWidth);
	}
	if (m_iHeight < oGameObject->m_iHeight) {
		return maths::IsPointInside(m_iY, oGameObject->m_iY, oGameObject->m_iY + oGameObject->m_iHeight) ||
			   maths::IsPointInside(m_iY + m_iHeight, oGameObject->m_iY, oGameObject->m_iY + oGameObject->m_iHeight);
	}
	else {
		return maths::IsPointInside(oGameObject->m_iY, m_iY, m_iY + m_iHeight) ||
			   maths::IsPointInside(oGameObject->m_iY + oGameObject->m_iHeight, m_iY, m_iY + m_iHeight);
	}
}

void GameObject::draw() {

}

void GameObject::rotate() {

}

void GameObject::move() {

}