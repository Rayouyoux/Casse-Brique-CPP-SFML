#pragma once
class Window;
class Cannon;
class Brick;
class Ball;
class PhysicalGameObject;
class GameObject;
#include <SFML/Graphics.hpp>
#include <list>

class GameManager
{
private:
	static std::list<PhysicalGameObject*> m_voPhysicalGameObjects;
	static std::list<GameObject*> m_voMoveObject;
	static std::list<Brick*> m_voBricks;

public:
	Window* m_oWindow;
	Cannon* m_oCannon;
	Brick* m_oBrick1;
	Brick* m_oBrick2;
	Ball* m_oBall;
	sf::Clock m_oClock;
	float m_fDeltaTime;
	float m_fMousePosition[2];

	GameManager();
	void setLevel();
	void gameLoop();
	void eventLoop();
	void handleCollision();
	void move();
	int tryDestroy();
	void destroy(int iIndice);

	static std::list<PhysicalGameObject*>::iterator AddPhysicalGameObject(PhysicalGameObject* go);
	static std::list<GameObject*>::iterator AddMovingGameObject(GameObject* go);
	static std::list<Brick*>::iterator AddBrick(Brick* brick);
	static void RemovePhysicalGameObject(std::list<PhysicalGameObject*>::iterator oIterator);
	static void RemoveMovingGameObject(std::list<GameObject*>::iterator oIterator);
	static void RemoveBrick(std::list<Brick*>::iterator oIterator);

	~GameManager();
};

