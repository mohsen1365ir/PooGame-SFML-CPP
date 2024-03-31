#pragma once

#include <SFML/Graphics.hpp>
#include "Poo.h"

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
    // void moveForward();
    // sf::Vector2f getCenterPosition() const;
    void update(Poo[]);
    bool isColliding(Poo) const;
    void draw(sf::RenderWindow &) const;
};