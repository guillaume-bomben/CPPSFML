#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

class GameObject {
protected:
    sf::RectangleShape rectangleShape;  // si rectangle
    sf::CircleShape circleShape;        // si cercle
    sf::Vector2f position;              // Position de l'obj
    sf::Vector2f velocity;              // Vitesse de déplacement
    float rotationSpeed;                // Vitesse de rotation


public:
    GameObject(bool isRectangle, sf::Vector2f size, sf::Vector2f position);

    // Methodes pour deplacer et tourné l'objet
    void setVelocity(sf::Vector2f vel);
    void update(float deltaTime);       //update déplacements
    void rotate(float angle);           // Rotation
    void draw(sf::RenderWindow& window); // Affichage

    //collision
    sf::FloatRect getBounds() const;
    bool checkCollision(const GameObject& other) const;
};


#endif
