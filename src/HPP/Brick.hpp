#ifndef BRICK_HPP
#define BRICK_HPP

#include "GameObject.hpp"

class Brick : public GameObject{

    public:
        Brick();
        Brick(sf::Vector2f position, const sf::Texture& texturePath);
        ~Brick();
};

#endif