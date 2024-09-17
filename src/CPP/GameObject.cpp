#include "../HPP/GameObject.hpp"

GameObject::GameObject(sf::Vector2f position, sf::Vector2f size, const sf::Texture& texturePath) {
    this->position = position;
    this->size = size;
    this->TexturePath = texturePath;
}

GameObject::~GameObject() {}

void GameObject::update() {}

void GameObject::draw(sf::RenderWindow& window){
    sf::Sprite sprite;
    sprite.setTexture(TexturePath);
    sprite.setPosition(position);
    sprite.setScale(size.x, size.y);
    window.draw(sprite);
}

sf::Texture GameObject::getTexturePath() {
    return TexturePath;
}