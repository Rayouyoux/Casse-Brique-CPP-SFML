#include "Cannon.h"
#include "window.h"

Cannon::Cannon(float fX, float fY, float fWidth, float fHeight, Window* oWindow) :
		GameObject(fX, fY, fWidth, fHeight, oWindow) {

}

void Cannon::rotate(sf::Vector2i* oMousePosition) {
	//if (oMousePosition->y < m_fY) {
	{
		setRotation(-atan2(oMousePosition->x - m_fX, oMousePosition->y - m_fY) * 180 / 3.14159);
	}
}

Cannon::~Cannon() {

}