#ifndef BALL_HPP
#define BALL_HPP

#include "GameObject.hpp"
#include "Brick.hpp"

class Ball : public GameObject{
    private:
        sf::Vector2f velocity = sf::Vector2f(0.5, 0.5);

    public:
        Ball();
        Ball(sf::Vector2f position, const sf::Texture& texturePath);
        ~Ball();
        void update();
        void isColliding(std::vector<Brick>& brick, sf::RenderWindow& window, bool& islaunch);
        void setVelocity(sf::Vector2f velocity);
};

#endif