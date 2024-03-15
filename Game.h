#pragma once

#include <SFML/Graphics.hpp>
#include "Poo.h"
#include "Dude.h"

class Game
{
private:
    sf::RenderWindow window;
    Poo poos[10];
    Dude dude = Dude(100,100);
public:
    Game(int, int);
    void run();
};