#pragma once

#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RenderWindow window;

public:
    Game(int, int);
    void run();
};