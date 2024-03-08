#pragma once

#include <SFML/Graphics.hpp>

class Poo: public sf::Sprite
{
private:
    sf::Texture image;
public:
    Poo();
    Poo(int, int);
};