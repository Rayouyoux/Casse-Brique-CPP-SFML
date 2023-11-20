#pragma once
class Window;
class PhysicalGameObject;
class GameObject;
class Zoobie;
class Location;
#include <SFML/Graphics.hpp>
#include <list>

class GameManager
{
private:
	static std::list<PhysicalGameObject*> m_voPhysicalGameObjects;
	static std::list<GameObject*> m_voMoveObject;
	static std::list<Zoobie*> m_voZoobies;
	static std::list<Location*> m_voLocations;
	static std::list<GameObject*> m_voDestroyObjects;

public:
	Window* m_oWindow;
	sf::Clock m_oClock;
	float m_fDeltaTime;
	float m_fMousePosition[2];

	GameManager();
	void gameLoop();
	void eventLoop();
	void handleCollision();
	void move();
	void destroy();

	static std::list<PhysicalGameObject*>::iterator AddPhysicalGameObject(PhysicalGameObject* go);
	static void RemovePhysicalGameObject(std::list<PhysicalGameObject*>::iterator oIterator);

	static std::list<GameObject*>::iterator AddMovingGameObject(GameObject* go);
	static void RemoveMovingGameObject(std::list<GameObject*>::iterator oIterator);

	static std::list<Zoobie*>::iterator AddZoobie(Zoobie* go);
	static void RemoveZoobie(std::list<Zoobie*>::iterator oIterator);

	static std::list<Location*>::iterator AddLocation(Location* go);
	static void RemoveLocation(std::list<Location*>::iterator oIterator);

	static void AddDestroyObject(GameObject* go);

	~GameManager();
};
