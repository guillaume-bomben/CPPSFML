#ifndef MENU_HPP
#define MENU_HPP

#include "window.hpp"
#include "Game.hpp"

// The Menu class handles different menu states in the game.
class Menu {

    private:
        // Private members can be added here if needed.

    public:
        // Constructor for the Menu class.
        Menu();
        
        // Function to display the win menu.
        // Parameters:
        // - win: Reference to the Window object.
        // - state: Reference to the current state of the game as a string.
        // - game: Reference to the Game object.
        void winmenu(Window& win, std::string& state, Game& game);

        // Function to display the loose menu.
        // Parameters:
        // - win: Reference to the Window object.
        void loosemenu(Window& win);

        // Function to display the select menu.
        // Parameters:
        // - win: Reference to the Window object.
        // - state: Reference to the current state of the game as a string.
        void selectmenu(Window& win, std::string& state);

};

#endif