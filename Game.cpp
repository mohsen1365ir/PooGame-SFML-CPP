#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Poo.h"

Game::Game(int width, int height): window(sf::VideoMode(width, height), "SFML works!")
{
    window.setFramerateLimit(60);
    Poo::screenWidth = width;
    Poo::screenHeight = height;
}


void Game::run()
{
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    // Poo poo,poo1(700,350);

    while (window.isOpen())
    {
        for(int i = 0; i < 10; i++)
        {
            poos[i].moveForward();
        }
        // poo.moveForward();
        // poo1.moveForward();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // window.draw(shape);
        for(int i = 0; i < 10; i++)
        {
            // window.draw(poos[i].trace);
            window.draw(poos[i]);
        }
        // window.draw(poo.trace);
        // window.draw(poo1.trace);
        // window.draw(poo);
        // window.draw(poo1);
        window.display();
    }
}
