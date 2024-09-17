#include <SFML/Graphics.hpp>
#include <iostream>
#include "HPP/window.hpp"
#include <SFML/Window/Event.hpp>
int main() {
    Window win("Casse Brique", 1000, 600, 60);
    win.start();
    return 0;
}
