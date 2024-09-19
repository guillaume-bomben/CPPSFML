#include "../HPP/Brick.hpp"

Brick::Brick() : GameObject(sf::Vector2f(0, 0), sf::Vector2f(1, 1), sf::Texture()){}

Brick::Brick(sf::Vector2f position, const sf::Texture& texturePath) : GameObject(position, sf::Vector2f(0.25, 0.25), texturePath){}

Brick::~Brick(){}