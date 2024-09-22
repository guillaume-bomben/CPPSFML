#include "../HPP/Menu.hpp"
#include "../HPP/window.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// Constructor for the Menu class
Menu::Menu(){};

// Function to display the loose menu
void Menu::loosemenu(Window& win){
    // Set the background image for the loose menu
    win.setBackground("image/brique.png");
};

// Function to display the win menu
void Menu::winmenu(Window& win, std::string& state, Game& game){
    // Set the background image for the win menu
    win.setBackground("image/loosemenu.png");
    win.display();

    sf::Event event;
    // Main loop to keep the window open
    while (win.getRenderWindow().isOpen()) {
        // Poll events from the window
        while (win.getRenderWindow().pollEvent(event)) {
            // If the user closes the window
            if (event.type == sf::Event::Closed) {
                win.getRenderWindow().close();
                return;
            }
            // If the user clicks the mouse button
            if (event.type == sf::Event::MouseButtonPressed) {
                // If the left mouse button is clicked
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if the click is within the specified area
                    if (event.mouseButton.x >= 310 && event.mouseButton.x <= 310 + 380 &&
                        event.mouseButton.y >= 202 && event.mouseButton.y <= 202 + 196) {
                        // Action to perform if the click is within the area
                        game.loadMatrix("Level/Level test.txt");
                        game.Win();
                        return; // Close the menu or move to another scene
                    }
                }
            }
        }
    }
};

// Function to display the select menu
void Menu::selectmenu(Window& win, std::string& state) {
    // Set the background image for the select menu
    win.setBackground("image/select menu.png");
    win.display();

    sf::Event event;
    // Main loop to keep the window open
    while (win.getRenderWindow().isOpen()) {
        // Poll events from the window
        while (win.getRenderWindow().pollEvent(event)) {
            // If the user closes the window
            if (event.type == sf::Event::Closed) {
                win.getRenderWindow().close();
                return;
            }

            // If the user clicks the mouse button
            if (event.type == sf::Event::MouseButtonPressed) {
                // If the left mouse button is clicked
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if the click is within the specified area
                    if (event.mouseButton.x >= 310 && event.mouseButton.x <= 310 + 380 &&
                        event.mouseButton.y >= 202 && event.mouseButton.y <= 202 + 196) {
                        // Action to perform if the click is within the area
                        state = "game";
                        return; // Close the menu or move to another scene
                    }
                }
            }
        }
    }
}
