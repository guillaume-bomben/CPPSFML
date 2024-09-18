#ifndef CANNON_HPP
#define CANNON_HPP

#include "GameObject.hpp"
#include "Ball.hpp"

class Cannon : public GameObject{
    private:
        float angle;

    public:
        bool isShooting = false;
        Cannon();
        Cannon(sf::Vector2f position, const sf::Texture& texturePath);
        ~Cannon();
        void rotate(sf::RenderWindow& window);
        float getAngle();
        void launch(Ball& ball);

};

#endif