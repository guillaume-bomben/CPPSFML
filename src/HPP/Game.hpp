#ifndef GAME_HPP
#define GAME_HPP

#include "Brick.hpp"
#include "Ball.hpp"
#include "Cannon.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// The Game class encapsulates the main functionality of the game,
// including loading resources, running the game loop, and checking win conditions.
class Game {
    private:
        // Matrix representing the game state
        std::vector<std::vector<int>> matrix;
        
        // Textures for game objects
        sf::Texture textureCannon;
        sf::Texture textureBall;    
        sf::Texture textureBrick;
        
        // Game objects
        std::vector<Brick> bricks;
        Cannon cannon;
        Ball ball;

    public:
        // Constructor that initializes the game with a given level file
        Game(std::string filename);
        
        // Destructor
        ~Game();
        
        // Main game loop
        void run(sf::RenderWindow& window);
        
        // Check if the player has won the game
        bool Win();
        
        // Load the game matrix from a file
        std::vector<std::vector<int>> loadMatrixFromFile(const std::string& filename);
        
        // Load the game matrix and initialize game objects
        void loadMatrix(const std::string& filename);
};

#endif