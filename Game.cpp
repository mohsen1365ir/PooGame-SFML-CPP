#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Poo.h"
#include "Dude.h"

Game::Game(int width, int height): window(sf::VideoMode(width, height), "SFML works!")
{
    window.setFramerateLimit(60);
    Poo::screenWidth = width;
    Poo::screenHeight = height;
    Dude::screenWidth = width;
    Dude::screenHeight = height;
}


void Game::run()
{

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        dude.update(poos);
        for(int i = 0; i < 10; i++)
        {
            // window.draw(poos[i].trace);
            poos[i].moveForward();
            poos[i].draw(window);
        }
        dude.draw(window);
        window.display();
    }
}
