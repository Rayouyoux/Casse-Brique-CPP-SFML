#include "Ball.h"
#include "maths.h"
#include "GameManager.h"

Ball::Ball(float fX, float fY, float fRadius) :
	PhysicalGameObject(fX, fY, fRadius) {
	m_oIteratorMove = GameManager::AddMovingGameObject(this);
}

void Ball::onCollisionEnter(int side) {
	if (side != 3) {
		maths::bounceVector(&m_oOrientation, side);
	}
	else {
		GameManager::AddDestroyObject(this);
	}
}

void Ball::onCollisionStay(int side) {

}

void Ball::onCollisionExit(int side) {

}

Ball::~Ball(){
	GameManager::RemoveMovingGameObject(m_oIteratorMove);
}