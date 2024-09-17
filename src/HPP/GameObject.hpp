#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

class GameObject {
protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture TexturePath;
    sf::Sprite sprite;


public:
    GameObject(sf::Vector2f position, sf::Vector2f size, const sf::Texture& texturePath);
    virtual ~GameObject();
    void draw(sf::RenderWindow& window);
    sf::Texture getTexturePath();
    sf::Vector2f getPosition();
};


#endif
