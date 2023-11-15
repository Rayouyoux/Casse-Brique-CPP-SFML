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
    PhysicalGameObject* oBall = new PhysicalGameObject(0, 0, 40, 40, oWindow);
    Cannon* oLine = new Cannon(0, 0, 5, 50, oWindow);
    oLine->setColor(sf::Color::Red);


    sf::Clock oClock;
    float fDeltaTime = 0;
    int bFixe = 0;

    while (oWindow->m_oWindow->isOpen())
    {
        sf::Event oEvent;
        while (oWindow->m_oWindow->pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed) {
                oWindow->close();
            }
            else if (oEvent.type == sf::Event::MouseButtonPressed) {
                if (oEvent.mouseButton.button == sf::Mouse::Left) {
                    bFixe = ( bFixe + 1 ) % 3;
                }
            }
        }
        sf::Vector2i oMousePosition = sf::Mouse::getPosition(*oWindow->m_oWindow);
        if (bFixe == 0) {
            oBall->setPosition(oMousePosition.x, oMousePosition.y);
            oLine->setPosition(oMousePosition.x, oMousePosition.y);
        }
        else if(bFixe == 1) {
            oLine->rotate(&oMousePosition);
        }
        else if (bFixe == 2) {
            oBall->m_oOrientation = maths::getOrientationVector(&oMousePosition, oBall->m_fX, oBall->m_fY);
            bFixe = (bFixe + 1) % 3;
        }

        /*oBall->move(fDeltaTime, 200.f);*/
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
