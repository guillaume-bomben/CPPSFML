#include <SFML/Graphics.hpp>
#include <iostream>
#include "HPP/window.hpp"
#include "HPP/InputManager.hpp"
#include <SFML/Window/Event.hpp>
int main() {

    Window win("Casse Brique", 1000, 600, 60);
    win.start();
    /*sf::RenderWindow window(sf::VideoMode(800, 600), "Test Input Manager");

    // Création d'un InputManager
    InputManager inputManager;

    // Binding de la touche A pour afficher un message
    inputManager.bindKey(sf::Keyboard::A, []() {
        std::cout << "Touche A pressée!" << std::endl;
    });

    // Binding de la touche ESCAPE pour fermer la fenêtre
    inputManager.bindKey(sf::Keyboard::Escape, [&window]() {
        window.close();
    });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Processus d'input
        inputManager.handleInput();

        window.clear();
        window.display();
    }*/

    return 0;
}
