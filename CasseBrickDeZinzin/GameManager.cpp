#include "GameManager.h"

#include "window.h"

#include "Cannon.h"
#include "Brick.h"
#include "Ball.h"

GameManager::GameManager() {

    m_oWindow = new Window(640, 480, "SFML");

    m_oCannon = new Cannon(320, 460, 20, 100, m_oWindow);
    m_oBrick1 = new Brick(3, 320, 240, 100, 100, m_oWindow, this);
    /*m_oBall = new Ball(0, 0, 20, m_oWindow, this);*/
    setLevel();
    /*Cannon* oLine = new Cannon(0, 0, 5, 50, oWindow);
    oLine->setColor(sf::Color::Red);*/


    /*sf::Clock oClock;*/
    m_fDeltaTime = 0;
    /*int bFixe = 0;*/
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

        handleCollision();

        m_oWindow->display();

        m_fDeltaTime = m_oClock.restart().asSeconds();
    }
}

void GameManager::setLevel() {
    for (int i = 0; i < 5; i++) {
        Brick* oBrick = new Brick(3, 70 + i * 100, 80, 80, 40, m_oWindow, this);
        m_voBricks.push_back(oBrick);
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
            m_fMousePosition[0] = oEvent.mouseMove.x;
            m_fMousePosition[1] = oEvent.mouseMove.y;
        }
        else if (oEvent.type == sf::Event::MouseButtonPressed) {
            if (oEvent.mouseButton.button == sf::Mouse::Left) {
                /*bFixe = ( bFixe + 1 ) % 3;*/
                m_oCannon->shoot(m_fMousePosition[0], m_fMousePosition[1], m_oWindow, this);
            }
        }
    }
}

void GameManager::handleCollision() {
    for (int i = 0; i < m_voPhysicalGameObjects.size(); i++) {
        if (m_voPhysicalGameObjects[i]->m_bMove) {
            m_voPhysicalGameObjects[i]->handleCollision(m_oWindow->m_oWindow);
        }
        for (int j = i + 1; j < m_voPhysicalGameObjects.size(); j++) {
            if (m_voPhysicalGameObjects[i]->m_bMove || m_voPhysicalGameObjects[j]->m_bMove) {
                m_voPhysicalGameObjects[i]->handleCollision(m_voPhysicalGameObjects[j]);
            }
        }
    }
    //m_oBall->handleCollision(m_oBrick1);
    //m_oBall->handleCollision(m_oWindow->m_oWindow);
}

void GameManager::move() {
    m_oBall->move(m_fDeltaTime, 200.f);
}

GameManager::~GameManager() {

}