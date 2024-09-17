#ifndef GAME_HPP
#define GAME_HPP

#include "window.hpp"

class Game {

    private:

    public:

    Game();
    
    void update();

    void render(sf::RenderWindow& window);

    bool isWon();

    bool isLost();

    void reset();

};
#endif