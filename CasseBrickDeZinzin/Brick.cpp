#include "Brick.h"
#include "maths.h"
#include <map>

std::map<int, sf::Color> HealthColorStates{
	{1, sf::Color(82, 214, 0)},
	{2, sf::Color(242, 214, 0)},
	{3, sf::Color(255, 106, 0)},
	{4, sf::Color(219, 18, 33)},
	{5, sf::Color(163, 29, 39)},
	{6, sf::Color(128, 33, 40)},
	{7, sf::Color(89, 30, 34)}
};

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
	m_oGraphic->setFillColor(HealthColorStates[m_iLife]);
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