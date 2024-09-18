#include "../HPP/Game.hpp"

Game::Game(){
    textureBrick.loadFromFile("image/brique.png");
    textureCannon.loadFromFile("image/canon.png");
    textureBall.loadFromFile("image/boule.png");

    cannon = Cannon(sf::Vector2f(500, 550), textureCannon);
    ball = Ball(sf::Vector2f(500, 500), textureBall);
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 3; j++){
            Brick brick(sf::Vector2f(0 + i * 150, 50 + j * 50), textureBrick);
            bricks.push_back(brick);
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