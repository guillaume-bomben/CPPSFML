#include "../HPP/Cannon.hpp"
#include <math.h>

Cannon::Cannon() : GameObject(sf::Vector2f(0, 0), sf::Vector2f(1, 1), sf::Texture()) {}

Cannon::Cannon(sf::Vector2f position, const sf::Texture& texturePath) : GameObject(position, sf::Vector2f(1, 1), texturePath) {
    this->angle = 0;
}

Cannon::~Cannon() {}

float Cannon::getAngle() {
    return angle;
}

void Cannon::rotate(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sf::Vector2f cannonPositionCenter = sprite.getPosition();
    sf::Vector2f direction = sf::Vector2f(mousePosition.x - cannonPositionCenter.x, mousePosition.y - cannonPositionCenter.y);
    angle = atan2(direction.y, direction.x) * 180 / M_PI;
    sprite.setRotation(angle);
}