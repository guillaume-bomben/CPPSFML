#include "../HPP/Brick.hpp"

// Default constructor for Brick class
// Initializes a Brick object with default position (0,0), size (1,1), and an empty texture
Brick::Brick() : GameObject(sf::Vector2f(0, 0), sf::Vector2f(1, 1), sf::Texture()) {}

// Parameterized constructor for Brick class
// Initializes a Brick object with given position and texture
// Size is set to (0.25, 0.25)
Brick::Brick(sf::Vector2f position, const sf::Texture& texturePath) : GameObject(position, sf::Vector2f(0.25, 0.25), texturePath) {}

// Destructor for Brick class
Brick::~Brick() {}