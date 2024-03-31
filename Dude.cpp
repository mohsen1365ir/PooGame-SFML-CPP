#include "Dude.h"
#include "Poo.h"
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

bool Dude::isColliding(const Poo &poo) const
{
    float dRight = x + Dude::width, dBottom = y + Dude::height;
    float pRight = poo.getX() + Poo::width, pBottom = poo.getY() + Poo::height;
    return dRight >= poo.getX() 
    &&     pRight >= x
    &&     dBottom >= poo.getY()
    &&     pBottom >= y;
}

// void Dude::moveForward()
// {
//     if(x+Dude::width>=Dude::screenWidth && xSpeed > 0.f) xSpeed *= -1;
//     if(y+Dude::height>=Dude::screenHeight && ySpeed > 0.f) ySpeed *= -1;
//     if(x<=0 && xSpeed < 0) xSpeed *= -1;
//     if(y<=0 && ySpeed < 0) ySpeed *= -1;
//     x += xSpeed;
//     y += ySpeed;
//     this->setPosition(x,y);
//     trace.append(getCenterPosition());
// }

// sf::Vector2f Dude::getCenterPosition() const
// {
//     return sf::Vector2f(static_cast<int>(x+Dude::width/2), static_cast<int>(y+Dude::height/2));
// }

void Dude::update(Poo poos[10])
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y>0)
    {
        y--;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (y+Dude::height<Dude::screenHeight))
    {
        y++;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x>0)
    {
        x--;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (x+Dude::width<Dude::screenWidth))
    {
        x++;
    }
    this->setPosition(x,y);

    for(int i=0; i < 10; i++)
    {
        if(isColliding(poos[i]))
        {
            poos[i].setIsEaten(true);
        }
    }
}

void Dude::draw(sf::RenderWindow &window) const
{
    window.draw(*this);
}

