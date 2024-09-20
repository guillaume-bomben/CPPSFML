#include "../HPP/Game.hpp"

Game::Game(std::string filename){
    textureBrick.loadFromFile("image/brique.png");
    textureCannon.loadFromFile("image/canon.png");
    textureBall.loadFromFile("image/boule.png");

    cannon = Cannon(sf::Vector2f(500, 550), textureCannon);
    ball = Ball(sf::Vector2f(500, 500), textureBall);

    matrix = loadMatrixFromFile(filename);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                Brick brick(sf::Vector2f(10 + i * 75, 10 + j * 25), textureBrick);
                bricks.push_back(brick);
            }
        }
    }

}

Game::~Game(){}

void Game::run(sf::RenderWindow& window){

    window.clear();
    cannon.draw(window);
    for(auto& brick : bricks){
        brick.draw(window);
    }
    cannon.rotate(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !cannon.isShooting){
        cannon.launch(ball);
        ball.setPosition(cannon.getPosition());
        ball.draw(window);
    }
    if (cannon.isShooting){
        ball.update();
        ball.isColliding(bricks, window, cannon.isShooting);
        ball.draw(window);
    }
    window.display();

}

bool Game::Win(){
    return bricks.empty();
}


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


void Game::loadMatrix(const std::string& filename){
    bricks.clear();
    matrix = loadMatrixFromFile(filename);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                Brick brick(sf::Vector2f(10 + i * 75, 10 + j * 25), textureBrick);
                bricks.push_back(brick);
            }
        }
    }
}