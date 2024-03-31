#pragma once

#include <SFML/Graphics.hpp>

class Poo: public sf::Sprite
{
private:
    sf::Texture image;
    float x,y;
    float xSpeed,ySpeed;
    bool isEaten = false;
public:
    sf::VertexArray trace;
    static int screenWidth,screenHeight;
    static int width,height;
    static bool isSetWidthHeight;
public:
    Poo();
    Poo(int, int);
    void moveForward();
    sf::Vector2f getCenterPosition() const;
    float getX() const;
    float getY() const;
    void setIsEaten(bool);
    void draw(sf::RenderWindow &) const;
};