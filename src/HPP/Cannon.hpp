#ifndef CANNON_HPP
#define CANNON_HPP

#include "GameObject.hpp"
#include "Ball.hpp"

// Cannon class inherits from GameObject
class Cannon : public GameObject {
    private:
        float angle; // Angle of the cannon

    public:
        bool isShooting = false; // Flag to check if the cannon is shooting

        // Default constructor
        Cannon();

        // Parameterized constructor
        Cannon(sf::Vector2f position, const sf::Texture& texturePath);

        // Destructor
        ~Cannon();

        // Method to rotate the cannon based on window input
        void rotate(sf::RenderWindow& window);

        // Method to get the current angle of the cannon
        float getAngle();

        // Method to launch a ball from the cannon
        void launch(Ball& ball);
};

#endif