#include "../HPP/Brick.hpp"

Brick::Brick(sf::Vector2f position, const sf::Texture& texturePath) : GameObject(position, sf::Vector2f(1, 1), texturePath){}

Brick::~Brick(){}