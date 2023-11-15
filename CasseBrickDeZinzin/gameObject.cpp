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

GameObject::~GameObject() {}