#include <SFML/Graphics.hpp>
#include "HPP/Game.hpp"
#include <vector>

int main(){
    auto window = sf::RenderWindow{ {1000u, 600u}, "Casse Brique test" };
    window.setFramerateLimit(144);
    Game game = Game("Level/Level1.txt");
    while (window.isOpen()){
        for (auto event = sf::Event{}; window.pollEvent(event);){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        if (!game.Win()){
            game.run(window);
        }
        else{
            window.clear(sf::Color::Green);
            window.display();
        }
        

    }

    return 0;
}