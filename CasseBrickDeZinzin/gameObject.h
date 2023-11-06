#pragma once

class Shape;

class GameObject {

public:

	GameObject(int iX, int iY, int iWidht, int iHeight, Shape* oGraphic);

	~GameObject();

	void setPosition(int iX, int iY);

	void setSize(int iWidth, int iHeight);

	bool isCollision(GameObject* oGameObject);

	int m_iX;
	int m_iY;
	int m_iWidth;
	int m_iHeight;
	Shape* m_oGraphic;

};

