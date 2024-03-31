#include "Poo.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
int Poo::screenWidth = 0;
int Poo::screenHeight = 0;
int Poo::width = 0;
int Poo::height = 0;
bool Poo::isSetWidthHeight = false;

Poo::Poo()
{
    this->x = rand()%800 + 1;
    this->y = rand()%400 + 1;
    this->xSpeed = (rand()%10)/5.0f-1;
    this->ySpeed = (rand()%10)/5.0f-1;
    // std::cout << this->xSpeed <<" " << this->ySpeed << std::endl; 
    image.loadFromFile("images/poo.png");
    this->setTexture(image);
    this->setScale(0.3,0.3);
    if(!Poo::isSetWidthHeight)
    {
        Poo::isSetWidthHeight = true;
        Poo::width = this->getGlobalBounds().width;
        Poo::height = this->getGlobalBounds().height;
    }
}

Poo::Poo(int x, int y):Poo()
{
    this->setPosition(x, y);
    this->x = x;
    this->y = y;
}

void Poo::moveForward()
{
    if(!isEaten)
    {
        if(x+Poo::width>=Poo::screenWidth && xSpeed > 0.f) xSpeed *= -1;
        if(y+Poo::height>=Poo::screenHeight && ySpeed > 0.f) ySpeed *= -1;
        if(x<=0 && xSpeed < 0) xSpeed *= -1;
        if(y<=0 && ySpeed < 0) ySpeed *= -1;
        x += xSpeed;
        y += ySpeed;
        this->setPosition(x,y);
        trace.append(getCenterPosition());
    }
}

sf::Vector2f Poo::getCenterPosition() const
{
    return sf::Vector2f(static_cast<int>(x+Poo::width/2), static_cast<int>(y+Poo::height/2));
}

float Poo::getX()
{
    return x;
}

float Poo::getY()
{
    return y;
}

void Poo::setIsEaten(bool eatenState)
{
    isEaten = eatenState;
}

void Poo::draw(sf::RenderWindow &window)
{
    if(!isEaten)
        window.draw(*this);
}
