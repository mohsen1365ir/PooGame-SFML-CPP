#include "Game.h"
#include <iostream>

int main()
{
    Game game(800,600);
    // std::cout << game.getSize().x ;
    game.init();
    game.loop();
    return 0;
}