#include "Cannon.h"
#include "window.h"

Cannon::Cannon(float fX, float fY, float fWidth, float fHeight, Window* oWindow) :
		GameObject(fX, fY, fWidth, fHeight, oWindow) {
}

void Cannon::shoot(float fMouseX, float fMouseY, Window* oWindow, GameManager* oGameManager) {
	Ball* newBall = new Ball(m_fX, m_fY, 20, oWindow, oGameManager);
	m_oOrientation = maths::getOrientationVector(m_fX, m_fY, fMouseX, fMouseY);
	newBall->setDirection(&m_oOrientation);
}

void Cannon::rotate(float fX, float fY) {
	if (fY < m_fY) {
		setRotation(-atan2(fX - m_fX, fY - m_fY) * 180 / 3.14159);
	}
}

Cannon::~Cannon() {

}