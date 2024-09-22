#include "../HPP/GameObject.hpp"

// Constructor for GameObject class
GameObject::GameObject(sf::Vector2f position, sf::Vector2f size, const sf::Texture& texturePath) {
    this->position = position; // Set the position of the GameObject
    this->size = size; // Set the size of the GameObject
    sprite.setTexture(texturePath); // Set the texture of the sprite
}

// Destructor for GameObject class
GameObject::~GameObject() {}

// Method to draw the GameObject on the window
void GameObject::draw(sf::RenderWindow& window){
    sprite.setPosition(position); // Set the position of the sprite
    sprite.setScale(size.x, size.y); // Set the scale of the sprite
    window.draw(sprite); // Draw the sprite on the window
}

// Method to get the texture path of the GameObject
sf::Texture GameObject::getTexturePath() {
    return TexturePath; // Return the texture path
}

// Method to get the position of the GameObject
sf::Vector2f GameObject::getPosition() {
    return position; // Return the position
}

// Method to set the position of the GameObject
void GameObject::setPosition(sf::Vector2f position) {
    this->position = position; // Set the position
}

// Method to get the sprite of the GameObject
sf::Sprite GameObject::getSprite() {
    return sprite; // Return the sprite
}