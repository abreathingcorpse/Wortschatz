#ifndef GAME_H // header guard
#define GAME_H

#ifndef SFML_H
#define SFML_H
#include <SFML/Graphics.hpp>
#endif // SFML_H header guard

#include "character.h++"

class Game {
    public:
        Game(); // Default Constructor
        void run();

    private:
        // Private methods
        void processEvents();
        void update();
        void render();
        void resizeToAspectRatio(float desired_aspect_ratio, float current_aspect_ratio);

        // Private members
        sf::RenderWindow mWindow;
        Character mPlayer;
        Character mEnemy;
        float mWindowWidth = 1920.f;
        float mWindowHeight = 1080.f;
        sf::View mView;

};

#endif // GAME_H header guard