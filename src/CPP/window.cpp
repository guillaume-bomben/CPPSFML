#include "../HPP/window.hpp"
#include "../HPP/Menu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// Constructeur : initialise la fenêtre
Window::Window(const std::string& title, unsigned int width, unsigned int height, unsigned int frameRate) 
    : title(title), videoMode(width, height), frameRate(frameRate), backgroundPath(""){
        create();
}

// Méthode pour initialiser la fenêtre
void Window::create() {
    // Crée une fenêtre
    win.create(videoMode, title);
    
    // Fixer les fps
    win.setFramerateLimit(frameRate);
}

//vérifier si la fenêtre est ouverte
bool Window::isOpen() const {
    return win.isOpen();
}

// fermer la fenêtre
void Window::close() {
    win.close();
}

// afficher des messages d'erreur
void Window::showError(const std::string& errorMessage) const {
    std::cerr << "Error: " << errorMessage << std::endl;
}

// obtenir les dimensions de la fenêtre
sf::Vector2u Window::getWindowSize() const {
    return win.getSize();

}

// obtenir le frame rate
unsigned int Window::getFrameRate() const {
    return frameRate;
}

// afficher le contenu dans la fenêtre
void Window::display() {
    win.clear();
    win.draw(backgroundSprite);
    win.display();
}

// récupérer l'objet SFML RenderWindow
sf::RenderWindow& Window::getRenderWindow() {
    return win;
}

// Méthode pour charger et afficher l'image de fond
void Window::setBackground(const std::string& path) {
    unloadBackground();
    backgroundPath = path;

    // Charger la texture de l'image de fond
    if (!backgroundTexture.loadFromFile(backgroundPath)) {
        showError("Failed to load background image from path: " + backgroundPath);
        return;
    }

    // Configurer le sprite avec la texture chargée
    backgroundSprite.setTexture(backgroundTexture);

    // Redimensionner le sprite pour couvrir toute la fenêtre
    backgroundSprite.setScale(
        static_cast<float>(videoMode.width) / backgroundTexture.getSize().x,
        static_cast<float>(videoMode.height) / backgroundTexture.getSize().y
    );
}

// Méthode pour décharger l'image de fond
void Window::unloadBackground() {
    // Réinitialiser la texture et le sprite de fond
    backgroundTexture = sf::Texture();  // Remet la texture à un état vierge
    backgroundSprite = sf::Sprite();    // Remet le sprite à un état vierge
}


void Window::start(){  
    while (isOpen()) {
        sf::Event event;
        while (getRenderWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                close();
            }
        }

        display();
    }
}


    /*Menu m;
    m.selectmenu(*this);*/