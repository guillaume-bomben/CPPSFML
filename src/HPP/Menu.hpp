#ifndef MENU_HPP
#define MENU_HPP

#include "window.hpp"
#include "Game.hpp"

class Menu {

    private:

    public:

    Menu();
    
    //menu win
    void winmenu(Window& win, std::string& state, Game& game);

    //menu loose
    void loosemenu(Window& win);

    //menu select
    void selectmenu(Window& win, std::string& state);

};
#endif