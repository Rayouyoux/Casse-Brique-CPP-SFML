#include "ball.h"
#include "maths.h"

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