#include "../HPP/Ball.hpp"

Ball::Ball(sf::Vector2f position, sf::Texture TexturePath) : GameObject(position, sf::Vector2f(1, 1), TexturePath){}

Ball::~Ball(){}

void Ball::update(){
    this->position += this->velocity;
    this->sprite.setPosition(this->position);
}

void Ball::isColliding(std::vector<Brick>& brick, sf::RenderWindow& window){
    // Utilisation d'un itérateur pour parcourir le vecteur et supprimer les briques
    for (auto it = brick.begin(); it != brick.end(); ){
        if (this->sprite.getGlobalBounds().intersects(it->getSprite().getGlobalBounds())){
            this->velocity.y = -this->velocity.y;
            it = brick.erase(it);  // Supprime la brique et met à jour l'itérateur
        } else {
            ++it;  // Avance l'itérateur seulement si pas de suppression
        }
    }

    // Gestion des collisions avec les bords de la fenêtre
    if (this->position.x < 0 || this->position.x > window.getSize().x){
        this->velocity.x = -this->velocity.x;
    }
    else if (this->position.y < 0 ){
        this->velocity.y = -this->velocity.y;
    }
}
