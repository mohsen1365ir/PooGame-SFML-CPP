#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RenderWindow window;

public:
    Game();
    void init();
    void loop();
};