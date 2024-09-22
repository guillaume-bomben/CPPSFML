#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

// The GameObject class represents a basic game object with position, size, texture, and sprite.
class GameObject {
protected:
    sf::Vector2f position; // Position of the game object in the game world.
    sf::Vector2f size;     // Size of the game object.
    sf::Texture TexturePath; // Texture of the game object.
    sf::Sprite sprite;     // Sprite representing the game object.

public:
    // Constructor to initialize the game object with position, size, and texture.
    GameObject(sf::Vector2f position, sf::Vector2f size, const sf::Texture& texturePath);
    
    // Virtual destructor to allow proper cleanup in derived classes.
    virtual ~GameObject();
    
    // Draws the game object on the given render window.
    void draw(sf::RenderWindow& window);
    
    // Returns the texture of the game object.
    sf::Texture getTexturePath();
    
    // Returns the position of the game object.
    sf::Vector2f getPosition();
    
    // Sets the position of the game object.
    void setPosition(sf::Vector2f position);
    
    // Returns the sprite of the game object.
    sf::Sprite getSprite();
};

#endif
