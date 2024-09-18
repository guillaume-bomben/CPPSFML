#include "../HPP/Game.hpp"

Game::Game(){
    textureBrick.loadFromFile("image/brique.png");
    textureCannon.loadFromFile("image/canon.png");
    textureBall.loadFromFile("image/boule.png");

    cannon = Cannon(sf::Vector2f(500, 550), textureCannon);
    ball = Ball(sf::Vector2f(500, 500), textureBall);
    ball.setVelocity(sf::Vector2f(2, -2));
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 3; j++){
            Brick brick(sf::Vector2f(0 + i * 150, 50 + j * 50), textureBrick);
            bricks.push_back(brick);
        }
    }
}

Game::~Game(){}

void Game::run(sf::RenderWindow& window){

    ball.update();
    ball.isColliding(bricks, window);
    

    window.clear();
    cannon.draw(window);
    for(auto& brick : bricks){
        brick.draw(window);
    }
    ball.draw(window);
    window.display();

    cannon.rotate(window);
}