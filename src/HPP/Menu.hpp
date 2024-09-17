#ifndef MENU_HPP
#define MENU_HPP

#include "window.hpp"

class Menu {

    private:

    public:

    enum GameState {
        selectmenu,
        winmenu,
        loosemenu,
        playing
    };

    Menu();
    
    //menu win
    void winmenu(Window& win);

    //menu loose
    void loosemenu(Window& win);

    //menu select
    void selectmenu(Window& win);

};
#endif