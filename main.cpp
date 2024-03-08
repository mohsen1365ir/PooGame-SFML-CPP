#include <SFML/Graphics.hpp>
#include <iostream>
#include "test.h"
int main()
{
    Test tt;
    std::cout << tt.a;
    tt.print();
    sf::RenderWindow window(sf::VideoMode(400, 300), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}