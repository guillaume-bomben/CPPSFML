#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

class GameObject {
protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture TexturePath;

public:
    GameObject(sf::Vector2f position, sf::Vector2f size, sf::Texture TexturePath);
    virtual ~GameObject();
    void update();
    void draw(sf::RenderWindow& window);
    sf::Texture getTexturePath();
};


#endif
