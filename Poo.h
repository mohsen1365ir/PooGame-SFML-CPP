#pragma once

#include <SFML/Graphics.hpp>

class Poo: public sf::Sprite
{
private:
    sf::Texture image;
    int x,y,xSpeed{1},ySpeed{1};
public:
    static int width,height;
public:
    Poo();
    Poo(int, int);
    void moveForward();
};