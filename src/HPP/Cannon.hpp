#ifndef CANNON_HPP
#define CANNON_HPP

#include "GameObject.hpp"

class Cannon : public GameObject{
    private:
        float angle;

    public:
        Cannon();
        Cannon(sf::Vector2f position, const sf::Texture& texturePath);
        ~Cannon();
        void rotate(sf::RenderWindow& window);
        float getAngle();

};

#endif