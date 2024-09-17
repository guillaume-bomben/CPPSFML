#ifndef BALL_HPP
#define BALL_HPP

#include "GameObject.hpp"

class Ball : public GameObject{
    private:
        sf::Vector2f velocity = sf::Vector2f(0.1, 0.1);

    public:
        Ball(sf::Vector2f position, sf::Texture TexturePath);
        ~Ball();
        void update();
        
};

#endif