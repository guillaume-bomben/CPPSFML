#include "../HPP/Menu.hpp"
#include "../HPP/window.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Menu::Menu(){};


void Menu::loosemenu(Window& win){
    win.setBackground("image/brique.png");
};

void Menu::winmenu(Window& win, std::string& state, Game& game){
    win.setBackground("image/loosemenu.png");
    win.display();

    sf::Event event;
    while (win.getRenderWindow().isOpen()) {
        // Récupération des événements
        while (win.getRenderWindow().pollEvent(event)) {
            // Si l'utilisateur ferme la fenêtre
            if (event.type == sf::Event::Closed) {
                win.getRenderWindow().close();
                return;
            }
                if (event.type == sf::Event::MouseButtonPressed) {

                // Si clic gauche
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Vérifier si le clic est dans la zone (310, 202) avec une taille de 380 par 196
                    if (event.mouseButton.x >= 310 && event.mouseButton.x <= 310 + 380 &&
                        event.mouseButton.y >= 202 && event.mouseButton.y <= 202 + 196) {
                        // Action à réaliser si le clic est dans la zone
                        game.loadMatrix("Level/Level test.txt");
                        game.Win();
                        return; // Fermer le menu ou passer à une autre scène
                    }
                }
            }
        }
    }
};

void Menu::selectmenu(Window& win, std::string& state) {
    // Définir l'arrière-plan
    win.setBackground("image/select menu.png");
    win.display();

    // Boucle principale du menu
    sf::Event event;
    while (win.getRenderWindow().isOpen()) {
        // Récupération des événements
        while (win.getRenderWindow().pollEvent(event)) {
            // Si l'utilisateur ferme la fenêtre
            if (event.type == sf::Event::Closed) {
                win.getRenderWindow().close();
                return;
            }

            // Gestion des clics de souris
            if (event.type == sf::Event::MouseButtonPressed) {

                // Si clic gauche
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Vérifier si le clic est dans la zone (310, 202) avec une taille de 380 par 196
                    if (event.mouseButton.x >= 310 && event.mouseButton.x <= 310 + 380 &&
                        event.mouseButton.y >= 202 && event.mouseButton.y <= 202 + 196) {
                        // Action à réaliser si le clic est dans la zone
                        state = "game";
                        return; // Fermer le menu ou passer à une autre scène
                    }
                }
            }
        }
    }
}
