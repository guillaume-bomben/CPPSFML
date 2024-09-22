#include "../HPP/Ball.hpp"

// Default constructor initializing the ball with default position and velocity
Ball::Ball() : GameObject(sf::Vector2f(0, 0), sf::Vector2f(1, 1), sf::Texture()) {}

// Parameterized constructor initializing the ball with given position and texture
Ball::Ball(sf::Vector2f position, const sf::Texture& texturePath) : GameObject(position, sf::Vector2f(0.25, 0.25), texturePath) {}

// Destructor
Ball::~Ball() {}

// Update the ball's position based on its velocity
void Ball::update() {
    this->position += this->velocity;  // Update position
    this->sprite.setPosition(this->position);  // Update sprite position
}

// Check for collisions with bricks and window bounds
void Ball::isColliding(std::vector<Brick>& bricks, sf::RenderWindow& window, bool& islaunch) {
    // Iterate through each brick to check for collisions
    for (auto it = bricks.begin(); it != bricks.end();) {
        if (this->sprite.getGlobalBounds().intersects(it->getSprite().getGlobalBounds())) {
            
            // Get bounds of the ball and the brick
            sf::FloatRect ballBounds = this->sprite.getGlobalBounds();
            sf::FloatRect brickBounds = it->getSprite().getGlobalBounds();

            // Check from which side the ball is colliding with the brick
            float overlapLeft = ballBounds.left + ballBounds.width - brickBounds.left;
            float overlapRight = brickBounds.left + brickBounds.width - ballBounds.left;
            float overlapTop = ballBounds.top + ballBounds.height - brickBounds.top;
            float overlapBottom = brickBounds.top + brickBounds.height - ballBounds.top;

            // Find the smallest overlap to determine the collision direction
            bool fromLeft = overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom;
            bool fromRight = overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom;
            bool fromTop = overlapTop < overlapLeft && overlapTop < overlapRight && overlapTop < overlapBottom;
            bool fromBottom = overlapBottom < overlapLeft && overlapBottom < overlapRight && overlapBottom < overlapTop;

            // Adjust the ball's velocity based on the side it collided with
            if (fromLeft || fromRight) {
                this->velocity.x = -this->velocity.x;  // Horizontal collision
            } else if (fromTop || fromBottom) {
                this->velocity.y = -this->velocity.y;  // Vertical collision
            }

            // Erase the brick from the vector
            it = bricks.erase(it);
        } else {
            ++it;  // Move to the next brick
        }
    }

    // Check window bounds for collisions
    if (this->position.x < 0 || this->position.x + this->sprite.getGlobalBounds().width > window.getSize().x) {
        this->velocity.x = -this->velocity.x;  // Bounce off left/right window edges
    }
    if (this->position.y < 0) {
        this->velocity.y = -this->velocity.y;  // Bounce off top window edge
    }
    
    // If the ball hits the bottom window edge, stop the launch
    if (this->position.y + this->sprite.getGlobalBounds().height > window.getSize().y) {
        islaunch = false;
    }
}

// Set the ball's velocity
void Ball::setVelocity(sf::Vector2f velocity) {
    this->velocity = velocity;
}