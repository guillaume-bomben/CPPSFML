#include "../HPP/Ball.hpp"

Ball::Ball(sf::Vector2f position, sf::Texture TexturePath) : GameObject(position, sf::Vector2f(1, 1), TexturePath){}

Ball::~Ball(){}

void Ball::update(){
    this->position += this->velocity;
    this->sprite.setPosition(this->position);
}