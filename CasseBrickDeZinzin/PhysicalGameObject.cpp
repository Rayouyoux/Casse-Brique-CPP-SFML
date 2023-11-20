#include "PhysicalGameObject.h"
#include "gameObject.h"
#include "maths.h"
#include "window.h"
#include "GameManager.h"
#include <SFML/Graphics.hpp>


PhysicalGameObject::PhysicalGameObject(float fX, float fY, float fWidth, float fHeight) : 
					GameObject (fX, fY, fWidth, fHeight) {
	m_bWindowCollision = false;
	m_oIterator = GameManager::AddPhysicalGameObject(this);
}

PhysicalGameObject::PhysicalGameObject(float fX, float fY, float fRadius) :
	GameObject(fX, fY, fRadius) {
	m_bWindowCollision = false;
	m_oIterator = GameManager::AddPhysicalGameObject(this);
}

void PhysicalGameObject::handleCollision(PhysicalGameObject* oGameObject) {
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
			oGameObject->onCollisionEnter(sideCollision(oGameObject));
			m_oObjectCollision.push_back(oGameObject);
		}
		else {
			onCollisionStay(sideCollision(oGameObject));
			oGameObject->onCollisionStay(sideCollision(oGameObject));
		}
	}
	else
	{
		if (iIndex != m_oObjectCollision.end()) {
			onCollisionExit(sideCollision(oGameObject));
			oGameObject->onCollisionExit(sideCollision(oGameObject));
			m_oObjectCollision.erase(iIndex);
		}
	}
}


int PhysicalGameObject::sideCollision(PhysicalGameObject* oGameObject) {
	sf::Vector2f* oSegmentVector = new sf::Vector2f(0, 0);
	std::pair<int, float> fLenghtMax (0, 0);
	float fLength;
	float fCoefInverseVector[2];
	/*float fCoefVector[2];
	float fCoordIntersection[2];*/
	float fX;
	float fY;
	float fIntersectionX = 0;
	float fIntersectionY = 0;
	float fPointA[2];
	float fPointB[2];
	sf::Vector2f oInverseVector(m_oOrientation.x, m_oOrientation.y);
	maths::invertVector(&oInverseVector);

	/*Window::Clear();*/

	for (int i = 0; i < 4; i++) {
		/*fX = m_fX + m_fWidth;
		fY = m_fY + m_fHeight;*/
		fX = i % 2 == 0 ? m_fX : m_fX + m_fWidth;
		fY = i / 2 == 0 ? m_fY : m_fY + m_fHeight;
		maths::getCoefficientLine(&oInverseVector, fX, fY, fCoefInverseVector);
		//std::cout << fCoefInverseVector[0] << ";" << fCoefInverseVector[1] << std::endl;
		for (int j = 0; j < 4; j++) {
			if (j == 0 ) {
				fPointA[0] = oGameObject->m_fX;
				fPointA[1] = oGameObject->m_fY;

				fPointB[0] = oGameObject->m_fX + oGameObject->m_fWidth;
				fPointB[1] = oGameObject->m_fY;
			}
			else
			if (j == 1) {
				fPointA[0] = oGameObject->m_fX + oGameObject->m_fWidth;
				fPointA[1] = oGameObject->m_fY;

				fPointB[0] = oGameObject->m_fX + oGameObject->m_fWidth;
				fPointB[1] = oGameObject->m_fY + oGameObject->m_fHeight;
			}
			else
			if (j == 2) {

				fPointA[0] = oGameObject->m_fX;
				fPointA[1] = oGameObject->m_fY + oGameObject->m_fHeight;

				fPointB[0] = oGameObject->m_fX + oGameObject->m_fWidth;
				fPointB[1] = oGameObject->m_fY + oGameObject->m_fHeight;
			}
			else
			if (j == 3) {

				fPointA[0] = oGameObject->m_fX;
				fPointA[1] = oGameObject->m_fY;

				fPointB[0] = oGameObject->m_fX;
				fPointB[1] = oGameObject->m_fY + oGameObject->m_fHeight;
			}

			if(fPointA[0] == fPointB[0]){
				fIntersectionX = fPointA[0];
				fIntersectionY = maths::getVerticalIntersection(fCoefInverseVector[0], fCoefInverseVector[1], fIntersectionX);
			}
			else {
				fIntersectionY = fPointA[1];
				fIntersectionX = maths::getHorizontalIntersection(fCoefInverseVector[0], fCoefInverseVector[1], fIntersectionY);
			}

			/*Window::Line oLine1;

			oLine1.p[0].position.x = fX;
			oLine1.p[0].position.y = fY;

			oLine1.p[1].position.x = fX + 100 * oInverseVector.x;
			oLine1.p[1].position.y = fY + 100 * oInverseVector.y;

			Window::m_oDebugs.push_back(oLine1);

			Window::Line oLine2;

			oLine2.p[0].position.x = fPointA[0];
			oLine2.p[0].position.y = fPointA[1];

			oLine2.p[1].position.x = fPointB[0];
			oLine2.p[1].position.y = fPointB[1];

			Window::m_oDebugs.push_back(oLine2);*/

			bool IsInSegment1 = maths::isPointOnSegment(fPointA[0], fPointA[1], fPointB[0], fPointB[1], fIntersectionX, fIntersectionY);
			bool IsInSegment2 = maths::isPointOnSegment(fX, fY, fX + 100 * oInverseVector.x, fY + 100 * oInverseVector.y, fIntersectionX, fIntersectionY);

			if (IsInSegment1 && IsInSegment2 )
			{
				fLength = maths::getLengthSegment(fPointA[0], fPointA[1], fIntersectionX, fIntersectionY);
				/*std::cout << fLength << std::endl;*/
				if (fLength > fLenghtMax.second) {
					setDebugPosition(fIntersectionX, fIntersectionY);
					fLenghtMax.first = j == 1 || j == 2 ? 1 : 2;
					fLenghtMax.second = fLength;	
				}
			}

		}
	}
	//std::cout << fLenghtMax.first << std::endl;
	return fLenghtMax.first;
}

void PhysicalGameObject::handleCollision() {
	int sideCollsion = 0;
	if (m_fX < 0 || m_fX + m_fWidth > Window::m_oWindow->getSize().x) {
		sideCollsion = 1;
	}
	else if (m_fY < 0) {
		sideCollsion = 2;
	}
	else if (m_fY > Window::m_oWindow->getSize().y) {
		sideCollsion = 3;
	}
	if (sideCollsion != 0) {
		if (!m_bWindowCollision) {
			onCollisionEnter(sideCollsion);
			m_bWindowCollision = true;
		}
		else {
			onCollisionStay(sideCollsion);
		}
	}
	else
	{
		if (m_bWindowCollision) {
			onCollisionExit(sideCollsion);
			m_bWindowCollision = false;
		}
	}
}

void PhysicalGameObject::onCollisionEnter(int side) {

}

void PhysicalGameObject::onCollisionStay(int side) {

}

void PhysicalGameObject::onCollisionExit(int side) {

}

PhysicalGameObject::~PhysicalGameObject() {
	GameManager::RemovePhysicalGameObject(m_oIterator);
}