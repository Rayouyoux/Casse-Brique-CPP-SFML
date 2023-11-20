#pragma once

#include <string>

class ZoobiesType
{
public :

	std::string m_sName;
	float m_fHPMax;
	float m_fSpeed;
	float m_fDamage;
	/*Sprite*/

	ZoobiesType(std::string sName, float fHPMax, float fSpeed, float fDamage);
	~ZoobiesType();
};

