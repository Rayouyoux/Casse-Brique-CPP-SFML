#include "ZoobiesType.h"

ZoobiesType::ZoobiesType(std::string sName, float fHPMax, float fSpeed, float fDamage) {
	m_sName = sName;
	m_fHPMax = fHPMax;
	m_fSpeed = fSpeed;
	m_fDamage = fDamage;
}

ZoobiesType::~ZoobiesType() {}