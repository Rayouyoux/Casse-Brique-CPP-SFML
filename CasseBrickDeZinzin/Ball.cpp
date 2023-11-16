#include "Ball.h"
#include "maths.h"
#include "GameManager.h"

Ball::Ball(float fX, float fY, float fRadius, Window* oWindow, GameManager* oGameManager) :
	PhysicalGameObject(fX, fY, fRadius, oWindow, oGameManager) {
}

void Ball::onCollisionEnter(int side) {
	maths::bounceVector(&m_oOrientation, side);
}

void Ball::onCollisionStay(int side) {

}

void Ball::onCollisionExit(int side) {

}

Ball::~Ball(){

}