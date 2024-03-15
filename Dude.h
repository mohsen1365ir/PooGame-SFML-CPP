#pragma once

#include <SFML/Graphics.hpp>

class Dude: public sf::Sprite
{
private:
    sf::Texture image;
    float x,y;
    float xSpeed,ySpeed;
public:
    sf::VertexArray trace;
    static int screenWidth,screenHeight;
    static int width,height;
    static bool isSetWidthHeight;
public:
    Dude();
    Dude(int, int);
    void moveForward();
    sf::Vector2f getCenterPosition() const;
    void update();
};