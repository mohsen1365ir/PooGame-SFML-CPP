#include "Game.h"
#include <iostream>

int main()
{
    Game game(800,600);
    game.init();
    game.loop();
    return 0;
}