#include "Ball.h"
#include "maths.h"
#include "GameManager.h"

Ball::Ball(float fX, float fY, float fRadius) :
	PhysicalGameObject(fX, fY, fRadius) {
	m_oIteratorMove = GameManager::AddMovingGameObject(this);
}

void Ball::onCollisionEnter(int side) {
	maths::bounceVector(&m_oOrientation, side);
}

void Ball::onCollisionStay(int side) {

}

void Ball::onCollisionExit(int side) {

}

Ball::~Ball(){
	GameManager::RemoveMovingGameObject(m_oIteratorMove);
}