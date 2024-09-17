#ifndef BRICK_HPP
#define BRICK_HPP

#include "GameObject.hpp"

class Brick : public GameObject{
    private:
        sf::Vector2f size = sf::Vector2f(3, 2);

    public:
        Brick(sf::Vector2f position, sf::Texture TexturePath);
        ~Brick();
};

#endif