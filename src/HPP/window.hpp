#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Window {
private:
    sf::RenderWindow win;    // Fenêtre SFML
    sf::VideoMode videoMode;    // dimensions de la fenêtre
    std::string title;          // Titre de la fenêtre
    unsigned int frameRate;     // Frame rate (par défaut 144)
    std::string backgroundPath; // Chemin de l'image de fond
    sf::Texture backgroundTexture; // Texture de l'image de fond
    sf::Sprite backgroundSprite;   // Sprite pour l'image de fond

public:
    // Constructeur par défaut
    Window(const std::string& title = "Game Window", unsigned int width = 1000, unsigned int height = 600, unsigned int frameRate = 144);

    //initialiser la fenêtre
    void create();

    //vérifier si la fenêtre est ouverte
    bool isOpen() const;

    //fermer la fenêtre
    void close();

    //afficher des messages d'erreur
    void showError(const std::string& errorMessage) const;

    // obtenir les dimensions de la fenêtre
    sf::Vector2u getWindowSize() const;

    //obtenir le frame rate
    unsigned int getFrameRate() const;

    //afficher le contenu dans la fenêtre
    void display();

    //récupérer l'objet SFML RenderWindow
    sf::RenderWindow& getRenderWindow();

    // charger et afficher l'image de fond
    void setBackground(const std::string& path);

    // décharger l'image de fond
    void unloadBackground();

    // boucle principale
    void start();

};

#endif