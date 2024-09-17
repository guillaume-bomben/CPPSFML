#include <SFML/Graphics.hpp>
#include <iostream>
#include "HPP/window.hpp"
#include <SFML/Window/Event.hpp>
int main() {
    Window win("Mon Jeu Casse-Brique", 1000, 600, 60);
    while (win.isOpen()) {
        sf::Event event;
        while (win.getRenderWindow().pollEvent(event)) {




            // Fermer la fenêtre si l'utilisateur clique sur le bouton de fermeture
            if (event.type == sf::Event::Closed) {
                win.close();
            }
        }
        win.setBackground("image/brique.png");
        // Afficher la fenêtre et son contenu
        win.display();
    }

    return 0;
}
