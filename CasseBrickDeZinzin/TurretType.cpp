#include "TurretType.h"

TurretType::TurretType(std::string sName, float fHPMax, int iPrice, float fFirerate, float fDamage) {
	m_sName = sName;
	m_fHPMax = fHPMax;
	m_iPrice = iPrice;
	m_fFirerate = fFirerate;
	m_fDamage = fDamage;
}

TurretType::~TurretType() {}