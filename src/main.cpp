#include <SFML/Graphics.hpp>
#include "HPP/Brick.hpp"

int main(){
    auto window = sf::RenderWindow{ {1920u, 1080u}, "SFML Rotation Example" };
    window.setFramerateLimit(144);
    sf::Texture texture;
    texture.loadFromFile("image/brique.png");

    Brick gameObject(sf::Vector2f(100, 100), texture);

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
