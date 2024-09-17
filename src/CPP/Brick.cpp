#include "../HPP/Brick.hpp"

Brick::Brick(sf::Vector2f position, const sf::Texture& texturePath) : GameObject(position, sf::Vector2f(3, 2), texturePath){}

Brick::~Brick(){}