#include "gameObject.h"
#include "maths.h"
#include "window.h"
#include <iostream>

#include <list>

GameObject::GameObject(float fX, float fY, float fWidth, float fHeight) {
	m_fX = fX;
	m_fY = fY;
	m_fWidth = fWidth;
	m_fHeight = fHeight;

	m_oGraphic = new sf::RectangleShape(sf::Vector2f(fWidth, fHeight));
	m_oGraphic->setPosition(m_fX, m_fY);


	m_oIterator = Window::AddGameObject(this);


	/*m_bMove = false;*/
}

GameObject::GameObject(float fX, float fY, float fRadius) {
	m_fX = fX;
	m_fY = fY;
	m_fWidth = fRadius * 2;
	m_fHeight = fRadius * 2;
	m_oGraphic = new sf::CircleShape(fRadius);
	m_oGraphic->setPosition(m_fX, m_fY);
	m_oIterator = Window::AddGameObject(this);
	/*m_bMove = false;*/
}

void GameObject::setPosition(float fX, float fY) {
	m_fX = fX;
	m_fY = fY;
	m_oGraphic->setPosition(m_fX, m_fY);
}

void GameObject::setOrigin(float fX, float fY) {
	m_oGraphic->setOrigin(fX * m_fWidth, fY * m_fHeight);
}

void GameObject::move(float fDeltaTime, float fspeed) {
	float fX = m_fX + m_oOrientation.x * fDeltaTime * fspeed;
	float fY = m_fY + m_oOrientation.y * fDeltaTime * fspeed;
	setPosition(fX, fY);
	/*m_bMove = true;*/
}

void GameObject::setRotation(float fAngle) {
	m_oGraphic->setRotation(fAngle);
}

void GameObject::setDirection(sf::Vector2f* oDirection) {
	m_oOrientation = *oDirection;
	if (maths::normVector(&m_oOrientation) != 1) {
		maths::normalizeVector(&m_oOrientation);
	}
}

//void GameObject::setColor(const sf::Color& oColor) {
//	m_oGraphic->setFillColor(oColor);
//}

GameObject::~GameObject() {
	Window::RemoveGameObject(m_oIterator);
}