#pragma once

#include <SFML/Graphics.hpp>

class Poo: public sf::Sprite
{
private:
    sf::Texture image;
    int x,y,xSpeed{1},ySpeed{1};
public:
    sf::VertexArray trace;
    static int screenWidth,screenHeight;
    static int width,height;
    static bool isSetWidthHeight;
public:
    Poo();
    Poo(int, int);
    void moveForward();
};