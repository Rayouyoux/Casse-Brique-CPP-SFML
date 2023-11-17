//#include "inputManager.h"
//#include "GameManager.h"
//#include "window.h"
//
//inputManager::inputManager() {
//
//}
//
//void inputManager::addEvent(sf::Event::EventType oEventType, void (GameManager::* function)()) {
//	m_mEvents.insert(std::pair<sf::Event::EventType, void (GameManager::*)()>(oEventType, function));
//}
//
//void inputManager::addMouseEvent(sf::Mouse::Button oEventType, void (GameManager::* function)()) {
//    m_mMouseEvents.insert(std::pair<sf::Mouse::Button, void (GameManager::*)()>(oEventType, function));
//    m_mEvents.insert(std::pair<sf::Event::EventType, void (GameManager::*)()>(sf::Event::MouseButtonPressed, function));
//}
//
//void inputManager::eventloop() {
//    sf::Event oEvent;
//    while (Window::m_oWindow->pollEvent(oEvent))
//    {
//        for (auto it = m_mEvents.begin(); it != m_mEvents.end(); ++it)
//        {
//            if (it->first == oEvent.type) {
//                if (it->first == sf::Event::MouseButtonPressed) {
//                    for (auto it2 = m_mEvents.begin(); it2 != m_mEvents.end(); ++it2) {
//                        if (it->first == oEvent.mouseButton.button) {
//                            it->second;
//                        }
//                    }
//                }
//                else {
//                    it->second;
//                }
//            }
//        }
//    }
//}
//
//inputManager::~inputManager() {
//
//}