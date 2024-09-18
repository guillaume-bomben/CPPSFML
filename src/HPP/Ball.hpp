#ifndef BALL_HPP
#define BALL_HPP

#include "GameObject.hpp"
#include "Brick.hpp"

class Ball : public GameObject{
    private:
        sf::Vector2f velocity = sf::Vector2f(0.5, 0.5);

    public:
        Ball(sf::Vector2f position, sf::Texture TexturePath);
        ~Ball();
        void update();
        void isColliding(std::vector<Brick>& brick, sf::RenderWindow& window);
};

#endif