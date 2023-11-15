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
	m_oDebugPoint = new sf::CircleShape(5);
	m_oDebugPoint->setFillColor(sf::Color::Red);
	m_bDrawDebug = false;
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
	m_oDebugPoint = new sf::CircleShape(5);
	m_oDebugPoint->setFillColor(sf::Color::Red);
	m_bDrawDebug = false;
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
}

void GameObject::setRotation(float fAngle) {
	m_oGraphic->setRotation(fAngle);
}

void GameObject::setColor(const sf::Color& oColor) {
	m_oGraphic->setFillColor(oColor);
}

void GameObject::setDebugPosition(float fX, float fY)
{
	m_bDrawDebug = true;

	m_oDebugPoint->setOrigin(5 / 2.f, 5 / 2.f);
	m_oDebugPoint->setPosition(fX, fY);
}

void GameObject::draw(Window* oWindow) {
	oWindow->m_oWindow->draw(*m_oGraphic);

	if(m_bDrawDebug)
		oWindow->m_oWindow->draw(*m_oDebugPoint);
}

GameObject::~GameObject() {}