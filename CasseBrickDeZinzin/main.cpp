#include "gameObject.h"
#include "maths.h"

#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");
    sf::Vector2i test(1, 1);

    GameObject* oRectangle = new GameObject(200, 20, 100, 100, &test);
    GameObject* oRectangle2 = new GameObject(320, 240, 100, 100, &test);
    GameObject* oCircle = new GameObject(0, 0, 50, &test);

    sf::Clock oClock;
    float fDeltaTime = 0;
    
    sf::Vector2f orientation = maths::getOrientationVector(&test, oCircle->m_fX, oCircle->m_fY);
    int iSideCollision;

    while (oWindow.isOpen())
    {
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }
        sf::Vector2i oMousePosition = sf::Mouse::getPosition(oWindow);
        //oCircle->setPosition(oMousePosition.x, oMousePosition.y);

        oCircle->move(fDeltaTime, 200.f);
        /*oRectangle2->move(fDeltaTime, sf::Vector2i(-1, -1), 100.f);*/
        /*oRectangle->rotate(&oMousePosition);*/


        oWindow.clear();

        oCircle->handleCollision(oRectangle2);
        oCircle->handleCollision(&oWindow);

        oWindow.draw(*oRectangle->m_oGraphic);
        oWindow.draw(*oRectangle2->m_oGraphic);
        oWindow.draw(*oCircle->m_oGraphic);

        oWindow.display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}
