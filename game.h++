#ifndef GAME_H // header guard
#define GAME_H

#ifndef SFML_H
#define SFML_H
#include <SFML/Graphics.hpp>
#endif // SFML_H header guard

class Game {
    public:
        Game(); // Default Constructor
        void run();

    private:
        // Private methods
        void processEvents();
        void update();
        void render();

        // Private members
        sf::RenderWindow mWindow;

};

#endif // GAME_H header guard