#include "Cannon.h"
#include "window.h"

Cannon::Cannon(float fX, float fY, float fWidth, float fHeight, Window* oWindow) :
		GameObject(fX, fY, fWidth, fHeight, oWindow) {
}

void Cannon::shoot(sf::Vector2f* orientation, Window* oWindow) {
	Ball* newBall = new Ball(m_fX, m_fY, 20, oWindow);
	newBall->setDirection(orientation);
}

sf::Vector2f Cannon::getOrientationVector(sf::Vector2i* oMousePosition, float fX, float fY) {
	sf::Vector2f orientationVector;
	orientationVector.x = oMousePosition->x - fX;
	orientationVector.y = oMousePosition->y - fY;
	maths::normalizeVector(&orientationVector);
	return orientationVector;
}

void Cannon::rotate(sf::Vector2i* oMousePosition) {
	if (oMousePosition->y < m_fY) {
		setRotation(-atan2(oMousePosition->x - m_fX, oMousePosition->y - m_fY) * 180 / 3.14159);
	}
}

Cannon::~Cannon() {

}