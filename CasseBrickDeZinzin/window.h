#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class GameObject;

class Window {

public:

	Window(int iWidth, int iHeight, std::string sWindowName);

	void display();
	void close();

	int m_iWidth;
	int m_iHeight;
	std::string m_sWindowName;
	std::vector<GameObject*> m_voWindowObjects;
	sf::RenderWindow* m_oWindow;

	~Window();

};