#include "PhysicalGameObject.h"
#include "gameObject.h"
#include "maths.h"
#include "window.h"
#include <SFML/Graphics.hpp>


PhysicalGameObject::PhysicalGameObject(float fX, float fY, float fWidth, float fHeight, Window* oWindow) : 
					GameObject (fX, fY, fWidth, fHeight, oWindow) {
	m_bWindowCollision = false;
}

PhysicalGameObject::PhysicalGameObject(float fX, float fY, float fRadius, Window* oWindow) :
	GameObject(fX, fY, fRadius, oWindow) {
	m_bWindowCollision = false;
}

void PhysicalGameObject::handleCollision(GameObject* oGameObject) {
	bool bCollisionX;
	bool bCollisionY;

	if (m_fWidth <= oGameObject->m_fWidth) {
		bCollisionX = maths::IsPointInside(m_fX, oGameObject->m_fX, oGameObject->m_fX + oGameObject->m_fWidth) || 
			maths::IsPointInside(m_fX + m_fWidth, oGameObject->m_fX, oGameObject->m_fX + oGameObject->m_fWidth);
			
	}
	else {
		bCollisionX = maths::IsPointInside(oGameObject->m_fX, m_fX, m_fX + m_fWidth) ||
			maths::IsPointInside(oGameObject->m_fX + oGameObject->m_fWidth, m_fX, m_fX + m_fWidth);
	}

	if (m_fHeight <= oGameObject->m_fHeight) {
		bCollisionY = maths::IsPointInside(m_fY, oGameObject->m_fY, oGameObject->m_fY + oGameObject->m_fHeight) || 
			maths::IsPointInside(m_fY + m_fHeight, oGameObject->m_fY, oGameObject->m_fY + oGameObject->m_fHeight);
		 	
	}
	else {
		bCollisionY = maths::IsPointInside(oGameObject->m_fY, m_fY, m_fY + m_fHeight) ||
			maths::IsPointInside(oGameObject->m_fY + oGameObject->m_fHeight, m_fY, m_fY + m_fHeight);
	}

	auto iIndex = std::find(m_oObjectCollision.begin(), m_oObjectCollision.end(), oGameObject);
	if (bCollisionX && bCollisionY) {
		if (iIndex == m_oObjectCollision.end()) {
			onCollisionEnter(sideCollision(oGameObject));
			//oGameObject->onCollisionEnter(sideCollision(oGameObject));
			m_oObjectCollision.push_back(oGameObject);
		}
		else {
			//onCollisionStay(sideCollision(oGameObject));
		}
	}
	else
	{
		if (iIndex != m_oObjectCollision.end()) {
			/*onCollisionExit(sideCollision(oGameObject));*/
			m_oObjectCollision.erase(iIndex);
		}
	}
}


int PhysicalGameObject::sideCollision(GameObject* oGameObject) {
	sf::Vector2f* oSegmentVector = new sf::Vector2f(0, 0);
	std::pair<int, float> fLenghtMax (0, 0);
	float fLength;
	float fCoefInverseVector[2];
	float fCoefVector[2];
	float fCoordIntersection[2];
	float fX;
	float fY;
	float fSegmentA[2];
	float fSegmentB[2];
	sf::Vector2f* oInverseVector = new sf::Vector2f(m_oOrientation.x, m_oOrientation.y);
	maths::invertVector(oInverseVector);

	for (int i = 0; i < 4; i++) {
		fX = i % 2 == 0 ? m_fX : m_fX + m_fWidth;
		fY = i / 2 == 0 ? m_fY : m_fY + m_fHeight;
		maths::getCoefficientLine(oInverseVector, fX, fY, fCoefInverseVector);
		for (int j = 0; j < 4; j++) {
			if (j % 2 == 0) {
				fSegmentA[0] = oGameObject->m_fX;
				fSegmentA[1] = oGameObject->m_fY;
			}
			else if (j == 1) {
				fSegmentA[0] = oGameObject->m_fX + oGameObject->m_fWidth;
				fSegmentA[1] = oGameObject->m_fY;
			}
			else {
				fSegmentA[0] = oGameObject->m_fX;
				fSegmentA[1] = oGameObject->m_fY + oGameObject->m_fHeight;
			}

			if (j % 2 == 1) {
				fSegmentB[0] = oGameObject->m_fX + oGameObject->m_fWidth;
				fSegmentB[1] = oGameObject->m_fY + oGameObject->m_fHeight;
			}
			else if (j == 0) {
				fSegmentB[0] = oGameObject->m_fX + oGameObject->m_fWidth;
				fSegmentB[1] = oGameObject->m_fY;
			}
			else {
				fSegmentB[0] = oGameObject->m_fX;
				fSegmentB[1] = oGameObject->m_fY + oGameObject->m_fHeight;
			}
			oSegmentVector->x = fSegmentB[0] - fSegmentA[0];
			oSegmentVector->y = fSegmentB[1] - fSegmentA[1];
			maths::normalizeVector(oSegmentVector);
			maths::getCoefficientLine(oSegmentVector, fSegmentA[0], fSegmentA[1], fCoefVector);
			maths::getIntersectionLine(fCoefInverseVector[0], fCoefInverseVector[1], fCoefVector[0], fCoefVector[1], fCoordIntersection);
			if (maths::isPointOnSegment(fSegmentA[0], fSegmentA[1], fSegmentB[0], fSegmentB[1], fCoordIntersection[0], fCoordIntersection[1])) {
				fLength = maths::getLengthSegment(fSegmentA[0], fSegmentA[1], fCoordIntersection[0], fCoordIntersection[1]);
				if (fLength > fLenghtMax.second) {
					fLenghtMax.first = j == 2 || j == 3 ? 1 : 2;
					fLenghtMax.second = fLength;
				}
			}
		}
	}
	std::cout << fLenghtMax.first << std::endl;
	return fLenghtMax.first;
}

void PhysicalGameObject::handleCollision(sf::RenderWindow* oWindow) {
	int sideCollsion = 0;
	if (m_fX < 0 || m_fX + m_fWidth > oWindow->getSize().x) {
		sideCollsion = 1;
	}
	else if (m_fY < 0 || m_fY + m_fHeight > oWindow->getSize().y) {
		sideCollsion = 2;
	}
	if (sideCollsion != 0) {
		if (!m_bWindowCollision) {
			onCollisionEnter(sideCollsion);
		}
		else {
			onCollisionStay(sideCollsion);
		}
	}
	else
	{
		if (m_bWindowCollision) {
			onCollisionExit(sideCollsion);
		}
	}
}

void PhysicalGameObject::onCollisionEnter(int side) {
	/*maths::bounceVector(&m_oOrientation, side);*/
}

void PhysicalGameObject::onCollisionStay(int side) {

}

void PhysicalGameObject::onCollisionExit(int side) {

}

PhysicalGameObject::~PhysicalGameObject() {

}