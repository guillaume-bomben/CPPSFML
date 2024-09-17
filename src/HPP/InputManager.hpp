#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <SFML/Window.hpp>
#include <functional>
#include <map>


class InputManager {
private:
    std::map<sf::Keyboard::Key, std::function<void()>> keyCallbacks;
    std::map<sf::Mouse::Button, std::function<void()>> mouseCallbacks;

public:
    // récupération des bouton presser
    void bindKey(sf::Keyboard::Key key, std::function<void()> func);
    void bindMouseButton(sf::Mouse::Button button, std::function<void()> func);

    // Appeler des fonction si touche presser
    void handleInput();
};


#endif
