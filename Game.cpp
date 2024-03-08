#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game(): window(sf::VideoMode(400, 300), "SFML works!"){}

void Game::init()
{
    window.setFramerateLimit(60);
    
    
}

void Game::loop()
{
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
}