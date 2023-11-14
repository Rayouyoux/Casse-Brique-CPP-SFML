#include "Brick.h"
#include "maths.h"

Brick::Brick(int iLife, float fX, float fY, float fWidth, float fHeight, Window* oWindow) :
	PhysicalGameObject(fX, fY, fWidth, fHeight, oWindow) {
	m_iLife = iLife;
	setColor();
}

void Brick::takeDamage() {
	m_iLife--;
	if (m_iLife == 0) {
		delete this;
	}
}

void Brick::setColor() {
	if (m_iLife == 3) {
		m_oGraphic->setFillColor(sf::Color(0, 255, 0));
	}
	else if(m_iLife == 2){
		m_oGraphic->setFillColor(sf::Color(255, 127, 0));
	}
	else if (m_iLife == 1) {
		m_oGraphic->setFillColor(sf::Color(255, 0, 0));
	}
}

void Brick::onCollisionEnter(int side) {
	maths::bounceVector(&m_oOrientation, side);
}

void Brick::onCollisionStay(int side) {

}

void Brick::onCollisionExit(int side) {

}

Brick::~Brick() {

}