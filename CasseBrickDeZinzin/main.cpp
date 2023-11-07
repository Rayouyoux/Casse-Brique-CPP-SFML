#include "gameObject.h"

#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");
    GameObject* oRectangle = new GameObject(0, 0, 100, 100);
    GameObject* oRectangle2 = new GameObject(640, 480, 100, 100);
    GameObject* oRectangle3 = new GameObject(0, 0, 100, 100);

    sf::Clock oClock;
    float fDeltaTime = 0;

    while (oWindow.isOpen())
    {
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }
        sf::Vector2i oMousePosition = sf::Mouse::getPosition(oWindow);

        oRectangle->move(fDeltaTime, sf::Vector2i(1, 1));
        oRectangle2->move(fDeltaTime, sf::Vector2i(-1, -1));
        oRectangle->rotate(&oMousePosition);


        oWindow.clear();

        if (oRectangle->isCollision(oRectangle2)) {
            oWindow.draw(*oRectangle3->m_oGraphic);
        }

        oWindow.draw(*oRectangle->m_oGraphic);
        oWindow.draw(*oRectangle2->m_oGraphic);

        oWindow.display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}
