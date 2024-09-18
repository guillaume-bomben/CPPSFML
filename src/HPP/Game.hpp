#ifndef GAME_HPP
#define GAME_HPP

#include "Brick.hpp"
#include "Ball.hpp"
#include "Cannon.hpp"


class Game{
    private:
        sf::Texture textureCannon;
        sf::Texture textureBall;    
        sf::Texture textureBrick;
        std::vector<Brick> bricks;
        Cannon cannon;
        Ball ball;

    public:
        Game();
        ~Game();
        void run(sf::RenderWindow& window);
};

#endif