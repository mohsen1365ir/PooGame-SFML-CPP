#pragma once

#include <SFML/Graphics.hpp>

class Poo: public sf::Sprite
{
private:
    sf::Texture image;
    int x,y,xSpeed{1},ySpeed{1};
public:
    static int screenWidth,screenHeight;
    static int width,height;
    static bool isSetWidthHeight;
public:
    Poo();
    Poo(int, int);
    void moveForward();
    sf::Vector2u getCenterPosition() const;
};