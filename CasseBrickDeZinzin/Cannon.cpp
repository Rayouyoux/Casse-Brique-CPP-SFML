#include "Cannon.h"
#include "window.h"

Cannon::Cannon(float fX, float fY, float fWidth, float fHeight) :
		GameObject(fX, fY, fWidth, fHeight) {
}

void Cannon::shoot(float fMouseX, float fMouseY) {
	Ball* newBall = new Ball(m_fX - m_fWidth / 4, m_fY, 20);
	m_oOrientation = maths::getOrientationVector(m_fX, m_fY, fMouseX, fMouseY);
	newBall->setDirection(&m_oOrientation);
}

void Cannon::rotate(float fX, float fY) {
	if (fY < m_fY) {
		setOrigin(0.5, 0);
		setRotation(-atan2(fX - m_fX, fY - m_fY) * 180 / 3.14159);
	}
}

Cannon::~Cannon() {

}