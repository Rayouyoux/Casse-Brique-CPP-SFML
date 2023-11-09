#include "gameObject.h"
#include "maths.h"

#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");
    GameObject* oRectangle = new GameObject(200, 20, 100, 100);
    GameObject* oRectangle2 = new GameObject(320, 240, 100, 100);
    GameObject* oRectangle3 = new GameObject(0, 0, 100, 100);
    GameObject* oCircle = new GameObject(0, 0, 50);

    sf::Clock oClock;
    float fDeltaTime = 0;
    sf::Vector2i test(1, 1);
    sf::Vector2f orientation = maths::getOrientationVector(test, oCircle->m_fX, oCircle->m_fY);
    int iCollision;

    while (oWindow.isOpen())
    {
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }
        sf::Vector2i oMousePosition = sf::Mouse::getPosition(oWindow);

        oCircle->move(fDeltaTime, orientation, 100.f);
        /*oRectangle2->move(fDeltaTime, sf::Vector2i(-1, -1), 100.f);*/
        /*oRectangle->rotate(&oMousePosition);*/


        oWindow.clear();

        if (oCircle->isCollision(oRectangle2)){
            oWindow.draw(*oRectangle3->m_oGraphic);
        }
        iCollision = oCircle->isCollision(&oWindow);
        if (iCollision != 0) {
            maths::bounceVector(&orientation, iCollision);
        }

        oWindow.draw(*oRectangle->m_oGraphic);
        oWindow.draw(*oRectangle2->m_oGraphic);
        oWindow.draw(*oCircle->m_oGraphic);

        oWindow.display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}
