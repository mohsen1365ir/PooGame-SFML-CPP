#include "Poo.h"
#include <iostream>
int Poo::screenWidth = 0;
int Poo::screenHeight = 0;
int Poo::width = 0;
int Poo::height = 0;
bool Poo::isSetWidthHeight = false;

Poo::Poo():x{0},y{0}
{
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
    if(x+Poo::width>=Poo::screenWidth && xSpeed > 0) xSpeed *= -1;
    if(y+Poo::height>=Poo::screenHeight && ySpeed > 0) ySpeed *= -1;
    if(x<=0 && xSpeed < 0) xSpeed *= -1;
    if(y<=0 && ySpeed < 0) ySpeed *= -1;
    x += xSpeed;
    y += ySpeed;
    this->setPosition(x,y);
}
