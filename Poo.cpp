#include "Poo.h"

Poo::Poo()
{
    image.loadFromFile("images/poo.png");
    pooSP.setTexture(image);
    pooSP.setScale(0.3,0.3);
}

void Poo::move(int x, int y){
    pooSP.move(x, y);
}