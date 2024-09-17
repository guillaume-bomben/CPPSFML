#include <SFML/Graphics.hpp>
#include "HPP/GameObject.hpp"

int main(){
    auto window = sf::RenderWindow{ {1920u, 1080u}, "SFML Rotation Example" };
    window.setFramerateLimit(144);
    sf::Texture texture;
    texture.loadFromFile("image/brique.png");

    GameObject gameObject(sf::Vector2f(100, 100), sf::Vector2f(5, 5), texture);

    while (window.isOpen()){
        for (auto event = sf::Event{}; window.pollEvent(event);){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear();
        gameObject.draw(window);
        window.display();

    }

    return 0;
}
