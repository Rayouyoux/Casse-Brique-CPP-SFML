#include "gameObject.h"
#include "maths.h"

GameObject::GameObject(float fX, float fY, float fWidth, float fHeight) {
	m_fX = fX;
	m_fY = fY;
	m_fWidth = fWidth;
	m_fHeight = fHeight;
	m_oGraphic = new sf::RectangleShape(sf::Vector2f(fWidth, fHeight));
	m_oGraphic->setPosition(m_fX, m_fY);
}

GameObject::GameObject(float fX, float fY, float fRadius) {
	m_fX = fX;
	m_fY = fY;
	m_fWidth = fRadius * 2;
	m_fHeight = fRadius * 2;
	m_oGraphic = new sf::CircleShape(fRadius);
	m_oGraphic->setPosition(m_fX, m_fY);
}

bool GameObject::isCollision(GameObject* oGameObject) {
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
    return bCollisionX + bCollisionY;
}

int GameObject::isCollision(sf::RenderWindow* oWindow) {
	if (m_fX < 0 || m_fX + m_fWidth > oWindow->getSize().x) {
		return 1;
	}
	else if (m_fY < 0 || m_fY + m_fHeight > oWindow->getSize().y) {
		return 2;
	}
	return 0;
}

void GameObject::move(float fDeltaTime, sf::Vector2f direction, float fspeed) {
	m_fX += direction.x * fDeltaTime * fspeed;
	m_fY += direction.y * fDeltaTime * fspeed;
	m_oGraphic->setPosition(m_fX, m_fY);
}

void GameObject::rotate(sf::Vector2i* oMousePosition) {
	m_oGraphic->setRotation(-atan2(oMousePosition->x - m_fX, oMousePosition->y - m_fY) * 180 / 3.14159);
}

GameObject::~GameObject() {}