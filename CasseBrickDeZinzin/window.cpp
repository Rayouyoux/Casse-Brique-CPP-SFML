#include "window.h"

#include "gameObject.h"

std::vector<Window::Line> Window::m_oDebugs;

Window::Window(int iWidth, int iHeight, std::string sWindowName) {

	m_iWidth = iWidth;
	m_iHeight = iHeight;
	m_sWindowName = sWindowName;
	m_oWindow = new sf::RenderWindow(sf::VideoMode(iWidth, iHeight), m_sWindowName);

}

void Window::display() {
	m_oWindow->clear();
	for (int i = 0; i < m_voWindowObjects.size(); i++) {
		m_voWindowObjects[i]->draw(this);
	}

	for (int i = 0; i < m_oDebugs.size(); i++) {
		m_oWindow->draw(m_oDebugs[i].p, 2, sf::Lines);
	}

	m_oWindow->display();
}

void Window::Clear() 
{
	m_oDebugs.clear();
}

void Window::close() {
	m_oWindow->close();
}

Window::~Window() {}