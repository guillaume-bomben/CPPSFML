#ifndef BRICK_HPP
#define BRICK_HPP

#include "GameObject.hpp"

// Brick class inherits from GameObject
class Brick : public GameObject {
    public:
        // Default constructor
        Brick();
        
        // Parameterized constructor
        // @param position: Position of the brick
        // @param texturePath: Texture to be applied to the brick
        Brick(sf::Vector2f position, const sf::Texture& texturePath);
        
        // Destructor
        ~Brick();
};

#endif