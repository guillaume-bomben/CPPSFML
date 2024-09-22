#ifndef BALL_HPP
#define BALL_HPP

#include "GameObject.hpp"
#include "Brick.hpp"

// Ball class inherits from GameObject
class Ball : public GameObject {
    private:
        // Velocity of the ball, initialized to (0.5, 0.5)
        sf::Vector2f velocity = sf::Vector2f(0.5, 0.5);

    public:
        // Default constructor
        Ball();

        // Parameterized constructor
        Ball(sf::Vector2f position, const sf::Texture& texturePath);

        // Destructor
        ~Ball();

        // Update the ball's state
        void update();

        // Check for collisions with bricks and handle them
        void isColliding(std::vector<Brick>& brick, sf::RenderWindow& window, bool& islaunch);

        // Set the velocity of the ball
        void setVelocity(sf::Vector2f velocity);
};

#endif