#pragma once

class Shape;

class GameObject {

public:

	GameObject(int iX, int iY, int iWidht, int iHeight);
	GameObject(int iX, int iY, int iRadius);

	~GameObject();

	/*void setPosition(int iX, int iY);

	void setSize(int iWidth, int iHeight);*/

	bool isCollision(GameObject* oGameObject);
	void draw();
	void rotate();
	void move();

	int m_iX;
	int m_iY;
	int m_iWidth;
	int m_iHeight;
	int m_iRadius;
	Shape* m_oGraphic;

};

