#include "../HPP/InputManager.hpp"

// Associer des événements clavier à des fonctions
void InputManager::bindKey(sf::Keyboard::Key key, std::function<void()> func) {
    keyCallbacks[key] = func;
}

// Associer des événements souris à des fonctions
void InputManager::bindMouseButton(sf::Mouse::Button button, std::function<void()> func) {
    mouseCallbacks[button] = func;
}

// Appeler les fonctions si les touches ou boutons sont pressés
void InputManager::handleInput() {
    for (const auto& [key, callback] : keyCallbacks) {
        if (sf::Keyboard::isKeyPressed(key)) {
            callback();  // Appel de la fonction associée à la touche
        }
    }
}