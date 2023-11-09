#include "gameObject.h"
#include "maths.h"

#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");
    GameObject* oRectangle = new GameObject(0, 0, 100, 100);
    GameObject* oRectangle2 = new GameObject(320, 240, 100, 100);
    GameObject* oRectangle3 = new GameObject(0, 0, 100, 100);
    GameObject* oCircle = new GameObject(200, 200, 50);

    sf::Clock oClock;
    float fDeltaTime = 0;
    sf::Vector2f orientation(1.f, 1.f);

    while (oWindow.isOpen())
    {
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }
        sf::Vector2i oMousePosition = sf::Mouse::getPosition(oWindow);

        oRectangle->move(fDeltaTime, orientation, 100.f);
        /*oRectangle2->move(fDeltaTime, sf::Vector2i(-1, -1), 100.f);*/
        /*oRectangle->rotate(&oMousePosition);*/


        oWindow.clear();

        if (oRectangle->isCollision(oRectangle2)){
            oWindow.draw(*oRectangle3->m_oGraphic);
        }
        int iCollision = oRectangle->isCollision(&oWindow);
        if (iCollision != 0) {
            orientation = maths::getOrientationVector(oMousePosition, oRectangle->m_fX, oRectangle->m_fY);
            maths::bounceVector(orientation, iCollision);
        }

        oWindow.draw(*oRectangle->m_oGraphic);
        oWindow.draw(*oRectangle2->m_oGraphic);
        oWindow.draw(*oCircle->m_oGraphic);

        oWindow.display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}
