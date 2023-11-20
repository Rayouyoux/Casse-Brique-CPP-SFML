#pragma once

#include <string>

class TurretType
{
public :

	std::string m_sName;
	float m_fHPMax;
	int m_iPrice;
	float m_fFirerate;
	float m_fDamage;
	/*Sprite
	Sprite Projectile*/

	TurretType(std::string sName, float fHPMax, int iPrice, float fFirerate, float fDamage);
	~TurretType();
};

