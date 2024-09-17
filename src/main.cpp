#include <SFML/Graphics.hpp>
#include <cmath> // Pour std::atan2 et std::sqrt

int main()
{
    auto window = sf::RenderWindow{ {1000u, 600u}, "SFML Rotation Example" };
    window.setFramerateLimit(144);

    // Charger l'image
    sf::Texture texture;
    if (!texture.loadFromFile("image/canon.png"))
    {
        return -1; // Erreur de chargement de l'image
    }
    sf::Sprite sprite(texture);

    // Obtenir la taille de la fenêtre
    sf::Vector2u windowSize = window.getSize();

    // Positionner le sprite au centre en bas de la fenêtre
    sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
    sprite.setPosition(windowSize.x / 2.0f, windowSize.y - sprite.getGlobalBounds().height / 2.0f);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Obtenir la position de la souris
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f spritePosition = sprite.getPosition();

        // Calculer l'angle de rotation
        float deltaX = static_cast<float>(mousePosition.x) - spritePosition.x;
        float deltaY = static_cast<float>(mousePosition.y) - spritePosition.y;
        float angle = std::atan2(deltaY, deltaX) * 180 / 3.14159265f; // Convertir radians en degrés

        // Appliquer la rotation
        sprite.setRotation(angle);

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
