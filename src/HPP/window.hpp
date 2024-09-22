#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <string>

// Class representing a game window
class Window {
private:
    sf::RenderWindow win;    // SFML window
    sf::VideoMode videoMode; // Window dimensions
    std::string title;       // Window title
    unsigned int frameRate;  // Frame rate (default 144)
    std::string backgroundPath; // Path to the background image
    sf::Texture backgroundTexture; // Texture for the background image
    sf::Sprite backgroundSprite;   // Sprite for the background image

public:
    // Default constructor
    // Initializes the window with a title, width, height, and frame rate
    Window(const std::string& title = "Game Window", unsigned int width = 1000, unsigned int height = 600, unsigned int frameRate = 144);

    // Creates the window with the specified parameters
    void create();

    // Checks if the window is open
    bool isOpen() const;

    // Closes the window
    void close();

    // Displays error messages
    void showError(const std::string& errorMessage) const;

    // Gets the window dimensions
    sf::Vector2u getWindowSize() const;

    // Gets the frame rate
    unsigned int getFrameRate() const;

    // Displays the content in the window
    void display();

    // Retrieves the SFML RenderWindow object
    sf::RenderWindow& getRenderWindow();

    // Loads and displays the background image
    void setBackground(const std::string& path);

    // Unloads the background image
    void unloadBackground();

    // Main loop of the window
    void start();
};

#endif