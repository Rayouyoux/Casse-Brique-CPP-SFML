#include "GameManager.h"

#include "window.h"

#include "Cannon.h"
#include "Brick.h"
#include "Ball.h"

std::list<PhysicalGameObject*> GameManager::m_voPhysicalGameObjects;
std::list<GameObject*> GameManager::m_voMoveObject;
std::list<Brick*> GameManager::m_voBricks;
std::list<GameObject*> GameManager::m_voDestroyObjects;

GameManager::GameManager() {

    m_oWindow = new Window(640, 480, "SFML");

    m_oCannon = new Cannon(320, 460, 20, 100);
    m_oBrick1 = new Brick(3, 320, 240, 100, 100, false);

    setLevel();

    m_fDeltaTime = 0;

    /* --- DEBUG --- */
    /*Cannon* oLine = new Cannon(0, 0, 5, 50, oWindow);
    oLine->setColor(sf::Color::Red);
    int bFixe = 0;*/
    
    gameLoop();
}

void GameManager::gameLoop() {
    while (m_oWindow->m_oWindow->isOpen())
    {
        eventLoop();
        
        /* --- DEBUG --- */

        /*if (bFixe == 0) {
            oBall->setPosition(oMousePosition.x, oMousePosition.y);
            oLine->setPosition(oMousePosition.x, oMousePosition.y);
        }
        else if(bFixe == 1) {
            oLine->rotate(&oMousePosition);
        }
        else if (bFixe == 2) {
            oBall->m_oOrientation = maths::getOrientationVector(&oMousePosition, oBall->m_fX, oBall->m_fY);
            bFixe = (bFixe + 1) % 3;
        }*/

        move();

        m_oCannon->rotate(m_fMousePosition[0], m_fMousePosition[1]);

        if (!m_voDestroyObjects.empty()) {
            destroy();
        }

        handleCollision();


        m_oWindow->display();

        m_fDeltaTime = m_oClock.restart().asSeconds();
    }
}

void GameManager::setLevel() {
    for (int i = 0; i < 5; i++) {
        Brick* oBrick = new Brick(3, 70 + i * 100, 80, 80, 40, false);
    }
}

void GameManager::eventLoop() {
    sf::Event oEvent;
    while (m_oWindow->m_oWindow->pollEvent(oEvent))
    {
        if (oEvent.type == sf::Event::Closed) {
            m_oWindow->close();
        }
        else if (oEvent.type == sf::Event::MouseMoved)
        {
            m_fMousePosition[0] = sf::Mouse::getPosition(*m_oWindow->m_oWindow).x;
            m_fMousePosition[1] = sf::Mouse::getPosition(*m_oWindow->m_oWindow).y;
        }
        else if (oEvent.type == sf::Event::MouseButtonPressed) {
            if (oEvent.mouseButton.button == sf::Mouse::Left) {
                /*bFixe = ( bFixe + 1 ) % 3;*/
                m_oCannon->shoot(m_fMousePosition[0], m_fMousePosition[1]);
            }
        }
    }
}

void GameManager::handleCollision() {


    for (auto it = m_voPhysicalGameObjects.begin(); it != m_voPhysicalGameObjects.end(); ++it)
    {
        if ((*it)->m_bMove) 
        {
            (*it)->handleCollision();
        }

        auto it2 = it;
        ++it2;
        for(it2; it2 != m_voPhysicalGameObjects.end(); ++it2)
        {
            if ((*it)->m_bMove || (*it2)->m_bMove)
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
        std::cout << "hello" << std::endl;
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

std::list<Brick*>::iterator GameManager::AddBrick(Brick* brick)
{
    m_voBricks.push_back(brick);

    auto it = m_voBricks.end();
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

void GameManager::RemoveBrick(std::list<Brick*>::iterator oIterator)
{
    m_voBricks.erase(oIterator);
}

GameManager::~GameManager() {

}