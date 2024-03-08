#include "Poo.h"

Poo::Poo()
{
    image.loadFromFile("images/poo.png");
    this->setTexture(image);
    this->setScale(0.3,0.3);
}

Poo::Poo(int x, int y):Poo()
{
    this->setPosition(x, y);
}

