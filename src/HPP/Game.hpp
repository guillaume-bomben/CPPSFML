#ifndef GAME_HPP
#define GAME_HPP

#include "Brick.hpp"
#include "Ball.hpp"
#include "Cannon.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


class Game{
    private:
        std::vector<std::vector<int>> matrix;
        sf::Texture textureCannon;
        sf::Texture textureBall;    
        sf::Texture textureBrick;
        std::vector<Brick> bricks;
        Cannon cannon;
        Ball ball;

    public:
        Game(std::string filename);
        ~Game();
        void run(sf::RenderWindow& window);
        bool Win();
        std::vector<std::vector<int>> loadMatrixFromFile(const std::string& filename);
        void loadMatrix(const std::string& filename);
};

#endif