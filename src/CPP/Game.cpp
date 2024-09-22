#include "../HPP/Game.hpp"

// Constructor for the Game class
Game::Game(std::string filename){
    // Load textures for the game objects
    textureBrick.loadFromFile("image/brique.png");
    textureCannon.loadFromFile("image/canon.png");
    textureBall.loadFromFile("image/boule.png");

    // Initialize the cannon and ball with their respective textures and positions
    cannon = Cannon(sf::Vector2f(500, 550), textureCannon);
    ball = Ball(sf::Vector2f(500, 500), textureBall);

    // Load the matrix from the file
    matrix = loadMatrixFromFile(filename);

    // Create bricks based on the matrix
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                Brick brick(sf::Vector2f(10 + i * 75, 10 + j * 25), textureBrick);
                bricks.push_back(brick);
            }
        }
    }
}

// Destructor for the Game class
Game::~Game(){}

// Main game loop
void Game::run(sf::RenderWindow& window){
    // Clear the window
    window.clear();

    // Draw the cannon
    cannon.draw(window);

    // Draw all the bricks
    for(auto& brick : bricks){
        brick.draw(window);
    }

    // Rotate the cannon
    cannon.rotate(window);

    // Check if the left mouse button is pressed and the cannon is not shooting
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !cannon.isShooting){
        // Launch the ball from the cannon
        cannon.launch(ball);
        ball.setPosition(cannon.getPosition());
        ball.draw(window);
    }

    // If the cannon is shooting, update the ball's position and check for collisions
    if (cannon.isShooting){
        ball.update();
        ball.isColliding(bricks, window, cannon.isShooting);
        ball.draw(window);
    }

    // Display the updated window
    window.display();
}

// Check if the player has won (i.e., all bricks are destroyed)
bool Game::Win(){
    return bricks.empty();
}

// Load the matrix from a file
std::vector<std::vector<int>> Game::loadMatrixFromFile(const std::string& filename) {
    std::vector<std::vector<int>> matrix;
    std::ifstream file(filename);
    
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<int> row;
            std::stringstream ss(line);
            int num;
            while (ss >> num) {
                row.push_back(num);
            }
            matrix.push_back(row);
        }
        file.close();
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
    }
    
    return matrix;
}

// Load a new matrix from a file and update the bricks
void Game::loadMatrix(const std::string& filename){
    // Clear the current bricks
    bricks.clear();

    // Load the new matrix from the file
    matrix = loadMatrixFromFile(filename);

    // Create new bricks based on the new matrix
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                Brick brick(sf::Vector2f(10 + i * 75, 10 + j * 25), textureBrick);
                bricks.push_back(brick);
            }
        }
    }
}