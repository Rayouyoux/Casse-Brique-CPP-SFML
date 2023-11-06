#include "gameObject.h"

GameObject::GameObject(int iX, int iY, int iWidth, int iHeight, Shape* oGraphic) {
	m_iX = iX;
	m_iY = iY;
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	m_oGraphic = oGraphic;
}

GameObject::~GameObject() {}

void GameObject::setPosition(int iX, int iY) {
	m_iX = iX;
	m_iY = iY;
}

void GameObject::setSize(int iWidth, int iHeight) {
	m_iWidth = iWidth;
	m_iHeight = iHeight;
}

bool GameObject::isCollision(GameObject* oGameObject) {
	if (m_iWidth < oGameObject->m_iWidth) {
		if ((m_iX >= oGameObject->m_iX && m_iX <= (oGameObject->m_iX + oGameObject->m_iWidth)) || ((m_iX + m_iWidth) >= oGameObject->m_iX && (m_iX + m_iWidth) <= (oGameObject->m_iX + oGameObject->m_iWidth))) {

		}
	}
	else {

	}
	if (m_iHeight < oGameObject->m_iHeight) {

	}
	else {

	}
	return false;
}