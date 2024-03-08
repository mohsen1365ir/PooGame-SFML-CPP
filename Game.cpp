#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Poo.h"

Game::Game(int x, int y): window(sf::VideoMode(x, y), "SFML works!")
{
    window.setFramerateLimit(60);
    Poo::width = x;
    Poo::height = y;
}

void Game::init()
{
    

    
}

void Game::loop()
{
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    Poo poo,poo1(700,350);

    while (window.isOpen())
    {
        poo.moveForward();
        poo1.moveForward();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // window.draw(shape);
        window.draw(poo);
        window.draw(poo1);
        window.display();
    }
}

sf::Vector2u Game::getSize()
{
    return window.getSize();
}