#pragma once

#include <SFML/Graphics.hpp>

class Poo
{
private:
    sf::Texture image;
public:
    sf::Sprite pooSP;
    Poo();
    void move(int, int);
};