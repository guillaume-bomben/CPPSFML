#include <SFML/Graphics.hpp>
#include "HPP/Ball.hpp"

int main(){
    auto window = sf::RenderWindow{ {1920u, 1080u}, "SFML Rotation Example" };
    window.setFramerateLimit(144);
    sf::Texture texture;
    texture.loadFromFile("image/boule.png");

    Ball gameObject(sf::Vector2f(100, 100), texture);

    while (window.isOpen()){
        for (auto event = sf::Event{}; window.pollEvent(event);){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        gameObject.update();
        
        window.clear();
        gameObject.draw(window);
        window.display();

        //gameObject.rotate(window);

    }

    return 0;
}