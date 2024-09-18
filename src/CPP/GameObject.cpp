#include "../HPP/GameObject.hpp"

GameObject::GameObject(sf::Vector2f position, sf::Vector2f size, const sf::Texture& texturePath) {
    this->position = position;
    this->size = size;
    sprite.setTexture(texturePath);
}

GameObject::~GameObject() {}

void GameObject::draw(sf::RenderWindow& window){
    sprite.setPosition(position);
    sprite.setScale(size.x, size.y);
    window.draw(sprite);
}

sf::Texture GameObject::getTexturePath() {
    return TexturePath;
}

sf::Vector2f GameObject::getPosition() {
    return position;
}

void GameObject::setPosition(sf::Vector2f position) {
    this->position = position;
}

sf::Sprite GameObject::getSprite() {
    return sprite;
}