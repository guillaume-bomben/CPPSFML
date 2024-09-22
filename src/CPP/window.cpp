#include "../HPP/window.hpp"
#include "../HPP/Menu.hpp"
#include "../HPP/Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// Constructor: initializes the window
Window::Window(const std::string& title, unsigned int width, unsigned int height, unsigned int frameRate) 
    : title(title), videoMode(width, height), frameRate(frameRate), backgroundPath("") {
        create();
}

// Method to initialize the window
void Window::create() {
    // Create a window
    win.create(videoMode, title);
    
    // Set the frame rate limit
    win.setFramerateLimit(frameRate);
}

// Check if the window is open
bool Window::isOpen() const {
    return win.isOpen();
}

// Close the window
void Window::close() {
    win.close();
}

// Display error messages
void Window::showError(const std::string& errorMessage) const {
    std::cerr << "Error: " << errorMessage << std::endl;
}

// Get the dimensions of the window
sf::Vector2u Window::getWindowSize() const {
    return win.getSize();
}

// Get the frame rate
unsigned int Window::getFrameRate() const {
    return frameRate;
}

// Display the content in the window
void Window::display() {
    win.clear();
    win.draw(backgroundSprite);
    win.display();
}

// Retrieve the SFML RenderWindow object
sf::RenderWindow& Window::getRenderWindow() {
    return win;
}

// Method to load and display the background image
void Window::setBackground(const std::string& path) {
    unloadBackground();
    backgroundPath = path;

    // Load the texture of the background image
    if (!backgroundTexture.loadFromFile(backgroundPath)) {
        showError("Failed to load background image from path: " + backgroundPath);
        return;
    }

    // Set up the sprite with the loaded texture
    backgroundSprite.setTexture(backgroundTexture);

    // Resize the sprite to cover the entire window
    backgroundSprite.setScale(
        static_cast<float>(videoMode.width) / backgroundTexture.getSize().x,
        static_cast<float>(videoMode.height) / backgroundTexture.getSize().y
    );
}

// Method to unload the background image
void Window::unloadBackground() {
    // Reset the background texture and sprite
    backgroundTexture = sf::Texture();  // Reset the texture to a blank state
    backgroundSprite = sf::Sprite();    // Reset the sprite to a blank state
}

// Start the main loop of the window
void Window::start() {  
    Game game = Game("Level/Level test.txt");  // Initialize the game with a level file
    Menu m;  // Initialize the menu
    std::string state = "menu";  // Set the initial state to "menu"
    
    // Main loop: runs while the window is open
    while (isOpen()) {
        sf::Event event;
        // Poll events
        while (getRenderWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                close();  // Close the window if the close event is triggered
            }
        }
        // Handle different states
        if (state == "menu") {
            m.selectmenu(*this, state);  // Display the menu
        }
        else if (state == "game") {
            if (!game.Win()) {
                game.run(win);  // Run the game if not won
            }
            else {
                m.winmenu(*this, state, game);  // Display the win menu if the game is won
            }
        }
    }
}