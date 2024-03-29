#include "Dude.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
int Dude::screenWidth = 0;
int Dude::screenHeight = 0;
int Dude::width = 0;
int Dude::height = 0;
bool Dude::isSetWidthHeight = false;

Dude::Dude()
{
    this->x = rand()%800 + 1;
    this->y = rand()%400 + 1;
    this->xSpeed = (rand()%10)/5.0f-1;
    this->ySpeed = (rand()%10)/5.0f-1;
    // std::cout << this->xSpeed <<" " << this->ySpeed << std::endl; 
    image.loadFromFile("images/dude.png");
    this->setTexture(image);
    this->setScale(0.3,0.3);
    if(!Dude::isSetWidthHeight)
    {
        Dude::isSetWidthHeight = true;
        Dude::width = this->getGlobalBounds().width;
        Dude::height = this->getGlobalBounds().height;
    }
}

Dude::Dude(int x, int y):Dude()
{
    this->setPosition(x, y);
    this->x = x;
    this->y = y;
}

void Dude::moveForward()
{
    if(x+Dude::width>=Dude::screenWidth && xSpeed > 0.f) xSpeed *= -1;
    if(y+Dude::height>=Dude::screenHeight && ySpeed > 0.f) ySpeed *= -1;
    if(x<=0 && xSpeed < 0) xSpeed *= -1;
    if(y<=0 && ySpeed < 0) ySpeed *= -1;
    x += xSpeed;
    y += ySpeed;
    this->setPosition(x,y);
    trace.append(getCenterPosition());
}

sf::Vector2f Dude::getCenterPosition() const
{
    return sf::Vector2f(static_cast<int>(x+Dude::width/2), static_cast<int>(y+Dude::height/2));
}

void Dude::update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->move(0,-1);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->move(0,1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->move(-1,0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->move(1,0);
    }
}