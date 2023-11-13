#include "Brick.h"

Brick::Brick(int iLife, float fX, float fY, float fWidth, float fHeight, Window* oWindow) :
	PhysicalGameObject(fX, fY, fWidth, fHeight, oWindow) {
	m_iLife = iLife;
}

void Brick::onCollisionEnter(int side) {
	/*maths::bounceVector(&m_oOrientation, side);*/
}

void Brick::onCollisionStay(int side) {

}

void Brick::onCollisionExit(int side) {

}

Brick::~Brick() {

}