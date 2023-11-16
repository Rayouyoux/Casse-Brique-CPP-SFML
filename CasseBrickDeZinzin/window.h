#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class GameObject;

class Window {
public:

	/*struct Line
	{
		sf::Vertex p[2];
	};*/


	Window(int iWidth, int iHeight, std::string sWindowName);

	void display();
	void close();

	int m_iWidth;
	int m_iHeight;
	std::string m_sWindowName;
	std::vector<GameObject*> m_voWindowObjects;
	sf::RenderWindow* m_oWindow;

	/*static std::vector<Line> m_oDebugs;*/

	/*static void Clear();*/

	~Window();

};