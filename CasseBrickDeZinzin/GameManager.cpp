#include "GameManager.h"

#include "window.h"
#include "PhysicalGameObject.h"
#include "GameObject.h"
#include "Zoobie.h"
#include "Location.h"

std::list<PhysicalGameObject*> GameManager::m_voPhysicalGameObjects;
std::list<GameObject*> GameManager::m_voMoveObject;
std::list<Zoobie*> GameManager::m_voZoobies;
std::list<Location*> GameManager::m_voLocations;
std::list<GameObject*> GameManager::m_voDestroyObjects;

GameManager::GameManager() {

    m_oWindow = new Window(1280, 800, "SFML");

    m_fDeltaTime = 0;

    gameLoop();
}

void GameManager::gameLoop() {
    while (m_oWindow->m_oWindow->isOpen())
    {
        eventLoop();

        move();

        handleCollision();

        if (!m_voDestroyObjects.empty()) {
            destroy();
        }

        m_oWindow->display();

        m_fDeltaTime = m_oClock.restart().asSeconds();
    }
}

void GameManager::eventLoop() {
    sf::Event oEvent;
    while (m_oWindow->m_oWindow->pollEvent(oEvent))
    {
        if (oEvent.type == sf::Event::Closed) {
            delete m_oWindow;
        }
        else if (oEvent.type == sf::Event::MouseMoved)
        {
            /*m_fMousePosition[0] = sf::Mouse::getPosition(*m_oWindow->m_oWindow).x;
            m_fMousePosition[1] = sf::Mouse::getPosition(*m_oWindow->m_oWindow).y;*/
        }
        else if (oEvent.type == sf::Event::MouseButtonPressed) {
            if (oEvent.mouseButton.button == sf::Mouse::Left) {
            }
        }
    }
}

void GameManager::handleCollision() {


    for (auto it = m_voPhysicalGameObjects.begin(); it != m_voPhysicalGameObjects.end(); ++it)
    {
        /*if ((*it)->m_bMove)*/
        {
            (*it)->handleCollision();
        }

        auto it2 = it;
        ++it2;
        for (it2; it2 != m_voPhysicalGameObjects.end(); ++it2)
        {
            /*if ((*it)->m_bMove || (*it2)->m_bMove)*/
            {
                (*it)->handleCollision(*it2);
            }
        }
    }
}

void GameManager::move() {
    for (auto it = m_voMoveObject.begin(); it != m_voMoveObject.end(); ++it)
    {
        (*it)->move(m_fDeltaTime, 200.f);
    }
}

void GameManager::destroy() {
    for (auto it = m_voDestroyObjects.rbegin(); it != m_voDestroyObjects.rend(); ++it)
    {
        GameObject* oGameObject = (*it);
        delete oGameObject;
    }
    m_voDestroyObjects.clear();
}

void GameManager::AddDestroyObject(GameObject* go)
{
    m_voDestroyObjects.push_back(go);
}

std::list<PhysicalGameObject*>::iterator GameManager::AddPhysicalGameObject(PhysicalGameObject* go)
{
    m_voPhysicalGameObjects.push_back(go);

    auto it = m_voPhysicalGameObjects.end();
    it--;
    return it;
}

std::list<GameObject*>::iterator GameManager::AddMovingGameObject(GameObject* go)
{
    m_voMoveObject.push_back(go);

    auto it = m_voMoveObject.end();
    it--;
    return it;
}

void GameManager::RemovePhysicalGameObject(std::list<PhysicalGameObject*>::iterator oIterator)
{
    m_voPhysicalGameObjects.erase(oIterator);
}

void GameManager::RemoveMovingGameObject(std::list<GameObject*>::iterator oIterator)
{
    m_voMoveObject.erase(oIterator);
}

std::list<Zoobie*>::iterator GameManager::AddZoobie(Zoobie* go)
{
    m_voZoobies.push_back(go);

    auto it = m_voZoobies.end();
    it--;
    return it;
}

void GameManager::RemoveZoobie(std::list<Zoobie*>::iterator oIterator)
{
    m_voZoobies.erase(oIterator);
}

std::list<Location*>::iterator GameManager::AddLocation(Location* go)
{
    m_voLocations.push_back(go);

    auto it = m_voLocations.end();
    it--;
    return it;
}

void GameManager::RemoveLocation(std::list<Location*>::iterator oIterator)
{
    m_voLocations.erase(oIterator);
}

GameManager::~GameManager() {

}