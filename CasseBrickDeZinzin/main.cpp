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

    Cannon* oCannon = new Cannon(320, 460, 20, 100, oWindow);
    Brick* oBrick1 = new Brick(3, 320, 240, 100, 100, oWindow);
    Brick* oBrick2 = new Brick(2, 150, 0, 90, 90, oWindow);
    Ball* oBall = new Ball(0, 0, 50, oWindow);

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
        oBall->setPosition(oMousePosition.x, oMousePosition.y);

        /*oCircle->move(fDeltaTime, 200.f);*/
        /*oBrick2->move(fDeltaTime, 300.f);*/

        oCannon->rotate(&oMousePosition);

        oBall->handleCollision(oBrick1);
        oBall->handleCollision(oWindow->m_oWindow);

        /*oBrick2->handleCollision(oBrick1);
        oBrick2->handleCollision(oWindow->m_oWindow);*/

        oWindow->display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}
