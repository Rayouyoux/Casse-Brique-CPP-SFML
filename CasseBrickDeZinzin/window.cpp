#include "window.h"

#include "gameObject.h"

//std::vector<Window::Line> Window::m_oDebugs;
std::list<GameObject*> Window::m_voWindowObjects;
sf::RenderWindow* Window::m_oWindow;

Window::Window(int iWidth, int iHeight, std::string sWindowName) {

	m_iWidth = iWidth;
	m_iHeight = iHeight;
	m_sWindowName = sWindowName;
	m_oWindow = new sf::RenderWindow(sf::VideoMode(iWidth, iHeight), m_sWindowName);

}

void Window::display() {
	m_oWindow->clear();

	for (auto it = m_voWindowObjects.begin(); it != m_voWindowObjects.end(); ++it) {
		(*it)->draw();
	}

	/*for (int i = 0; i < m_oDebugs.size(); i++) {
		m_oWindow->draw(m_oDebugs[i].p, 2, sf::Lines);
	}*/

	m_oWindow->display();
}

//void Window::Clear() 
//{
//	m_oDebugs.clear();
//}

void Window::close() {
	m_oWindow->close();
}

std::list<GameObject*>::iterator Window::AddGameObject(GameObject* go)
{
	m_voWindowObjects.push_back(go);

	auto it = m_voWindowObjects.end();
	it--;
	return it;
}

void Window::RemoveGameObject(std::list<GameObject*>::iterator oIterator)
{
	m_voWindowObjects.erase(oIterator);
}

Window::~Window() {}