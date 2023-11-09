#include "window.h"

#include "gameObject.h"
Window::Window(int iWidth, int iHeight, std::string sWindowName) {

	m_iWidth = iWidth;
	m_iHeight = iHeight;
	m_sWindowName = sWindowName;
	m_oWindow = new sf::RenderWindow(sf::VideoMode(iWidth, iHeight), m_sWindowName);

}

void Window::display() {
	for (int i = 0; i < m_voWindowObjects.size(); i++) {
		m_oWindow->draw(*m_voWindowObjects[i]->m_oGraphic);
	}
	m_oWindow->display();
}

void Window::close() {
	m_oWindow->close();
}

Window::~Window() {}