#pragma once
class Window;
class Cannon;
class Brick;
class Ball;
class PhysicalGameObject;
#include <SFML/Graphics.hpp>
#include <vector>

class GameManager
{
public:
	Window* m_oWindow;
	Cannon* m_oCannon;
	Brick* m_oBrick1;
	std::vector<Brick*> m_voBricks;
	Brick* m_oBrick2;
	Ball* m_oBall;
	sf::Clock m_oClock;
	float m_fDeltaTime;
	float m_fMousePosition[2];
	std::vector<PhysicalGameObject*>m_voPhysicalGameObjects;

	GameManager();
	void setLevel();
	void gameLoop();
	void eventLoop();
	void handleCollision();
	void move();
	~GameManager();
};

