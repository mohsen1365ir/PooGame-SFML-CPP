#pragma once

#include <SFML/Graphics.hpp>
#include "Poo.h"

class Game
{
private:
    sf::RenderWindow window;
    Poo poos[10];
public:
    Game(int, int);
    void run();
};