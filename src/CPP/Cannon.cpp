#include "../HPP/Cannon.hpp"
#include <math.h>
#include <iostream>

// Default constructor for Cannon, initializes with default position, scale, and texture
Cannon::Cannon() : GameObject(sf::Vector2f(0, 0), sf::Vector2f(1, 1), sf::Texture()) {}

// Parameterized constructor for Cannon, initializes with given position and texture
Cannon::Cannon(sf::Vector2f position, const sf::Texture& texturePath) : GameObject(position, sf::Vector2f(1, 1), texturePath) {
    this->angle = 0; // Initialize angle to 0
}

// Destructor for Cannon
Cannon::~Cannon() {}

// Getter for the angle of the cannon
float Cannon::getAngle() {
    return angle;
}

// Rotates the cannon to face the mouse cursor
void Cannon::rotate(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window); // Get the mouse position relative to the window
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2); // Set the origin to the center of the sprite
    sf::Vector2f cannonPositionCenter = sprite.getPosition(); // Get the current position of the cannon
    sf::Vector2f direction = sf::Vector2f(mousePosition.x - cannonPositionCenter.x, mousePosition.y - cannonPositionCenter.y); // Calculate direction vector from cannon to mouse
    angle = atan2(direction.y, direction.x) * 180 / M_PI; // Calculate the angle in degrees
    sprite.setRotation(angle); // Set the rotation of the sprite to the calculated angle
}

// Launches a ball from the cannon in the direction it is facing
void Cannon::launch(Ball& ball) {
    isShooting = true; // Set shooting flag to true
    sf::Vector2f direction = sf::Vector2f(cos(angle * M_PI / 180), sin(angle * M_PI / 180)); // Calculate direction vector based on the angle
    ball.setVelocity(direction * 5.0f); // Set the velocity of the ball in the calculated direction with a speed factor
}