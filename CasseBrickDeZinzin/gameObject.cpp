#include "gameObject.h"
#include "maths.h"
//#include <cmath>

GameObject::GameObject(float fX, float fY, float fWidth, float fHeight) {
	m_fX = fX;
	m_fY = fY;
	m_fWidth = fWidth;
	m_fHeight = fHeight;
	m_oGraphic = new sf::RectangleShape(sf::Vector2f(fWidth, fHeight));
}

GameObject::GameObject(float fX, float fY, float fRadius) {
	m_fX = fX;
	m_fY = fY;
	m_fRadius = fRadius;
	m_oGraphic = new sf::CircleShape(m_fRadius);
}

GameObject::~GameObject() {}

bool GameObject::isCollision(GameObject* oGameObject) {
	if (m_fWidth < oGameObject->m_fWidth) {
		return maths::IsPointInside(m_fX, oGameObject->m_fX, oGameObject->m_fX + oGameObject->m_fWidth) ||
			   maths::IsPointInside(m_fX + m_fWidth, oGameObject->m_fX, oGameObject->m_fX + oGameObject->m_fWidth);
	}
	else {
		return maths::IsPointInside(oGameObject->m_fX, m_fX, m_fX + m_fWidth) ||
			   maths::IsPointInside(oGameObject->m_fX + oGameObject->m_fWidth, m_fX, m_fX + m_fWidth);
	}
	if (m_fHeight < oGameObject->m_fHeight) {
		return maths::IsPointInside(m_fY, oGameObject->m_fY, oGameObject->m_fY + oGameObject->m_fHeight) ||
			   maths::IsPointInside(m_fY + m_fHeight, oGameObject->m_fY, oGameObject->m_fY + oGameObject->m_fHeight);
	}
	else {
		return maths::IsPointInside(oGameObject->m_fY, m_fY, m_fY + m_fHeight) ||
			   maths::IsPointInside(oGameObject->m_fY + oGameObject->m_fHeight, m_fY, m_fY + m_fHeight);
	}
}

void GameObject::move(float fDeltaTime, sf::Vector2i direction) {
	m_fX += direction.x * fDeltaTime * 100.f;
	m_fY += direction.y * fDeltaTime * 100.f;
	m_oGraphic->setPosition(m_fX, m_fY)	;
}

void GameObject::rotate(sf::Vector2i* oMousePosition) {
	m_oGraphic->setRotation(-atan2(oMousePosition->x - m_fX, oMousePosition->y - m_fY) * 180 / 3.14159);
}