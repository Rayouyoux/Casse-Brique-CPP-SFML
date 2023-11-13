#include "gameObject.h"
#include "maths.h"
#include "window.h"
#include "PhysicalGameObject.h"
#include "Cannon.h"
#include "Ball.h"
#include "Brick.h"

#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    Window* oWindow = new Window(640, 480, "SFML");
    /*sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");*/
    sf::Vector2i test(1, 1);

    Cannon* oCannon = new Cannon(320, 460, 20, 100, oWindow);
    Brick* oBrick1 = new Brick(0, 320, 240, 100, 100, &test, oWindow);
    Brick* oBrick2 = new Brick(0, 340, 290, 100, 100, &test, oWindow);
    Ball* oBall = new Ball(0, 0, 50, &test, oWindow);

    sf::Clock oClock;
    float fDeltaTime = 0;

    while (oWindow->m_oWindow->isOpen())
    {
        sf::Event oEvent;
        while (oWindow->m_oWindow->pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow->close();
        }
        sf::Vector2i oMousePosition = sf::Mouse::getPosition(*oWindow->m_oWindow);
        //oCircle->setPosition(oMousePosition.x, oMousePosition.y);

        /*oCircle->move(fDeltaTime, 200.f);*/
        /*oRectangle2->move(fDeltaTime, sf::Vector2i(-1, -1), 100.f);*/
        oCannon->rotate(&oMousePosition);

        /*oCircle->handleCollision(oRectangle2);
        oCircle->handleCollision(&oWindow);*/
        if (oMousePosition.y > oCannon->m_fY) {
            oBrick2->handleCollision(oBrick1);
        }

        oWindow->display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}
