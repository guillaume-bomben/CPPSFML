#include "../HPP/Brick.hpp"

Brick::Brick(sf::Vector2f position, sf::Texture TexturePath) : GameObject(position, this->size, TexturePath){}

Brick::~Brick(){}