#include "Ball.h"

Ball::Ball(float fX, float fY, float fRadius, Window* oWindow) :
	PhysicalGameObject(fX, fY, fRadius, oWindow) {
}

void Ball::onCollisionEnter(int side) {
	/*maths::bounceVector(&m_oOrientation, side);*/
}

void Ball::onCollisionStay(int side) {

}

void Ball::onCollisionExit(int side) {

}

Ball::~Ball(){

}