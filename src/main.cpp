#include <SFML/Graphics.hpp>
#include "HPP/Ball.hpp"
#include "HPP/Brick.hpp"
#include <vector>

int main(){
    auto window = sf::RenderWindow{ {1920u, 1080u}, "SFML Rotation Example" };
    window.setFramerateLimit(144);
    sf::Texture textureBall;
    sf::Texture textureBrick;
    std::vector<Brick> bricks;
    textureBall.loadFromFile("image/boule.png");
    textureBrick.loadFromFile("image/brique.png");


    Ball ball(sf::Vector2f(100, 100), textureBall);
    Brick brick(sf::Vector2f(200, 200), textureBrick);

    bricks.push_back(brick);

    while (window.isOpen()){
        for (auto event = sf::Event{}; window.pollEvent(event);){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        ball.update();
        ball.isColliding(bricks, window);
        
        window.clear();
        ball.draw(window);
        for (auto& b : bricks){
            b.draw(window);
        }
        window.display();

        //gameObject.rotate(window);

    }

    return 0;
}