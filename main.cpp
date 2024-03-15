#include "Game.h"
#include <iostream>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    Game game(800,600);
    
    game.run();
    return 0;
}