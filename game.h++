#ifndef GAME_H // header guard
#define GAME_H

#ifndef SFML_H
#define SFML_H
#include <SFML/Graphics.hpp>
#endif // SFML_H header guard

#include "character.h++"
//#include "card.h++"
#include <vector>

struct card {
    unsigned long ID;
    std::string front;
    std::string back;
    std::string track;
    std::string correct_cnt;
    std::string incorrect_cnt;
};

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
        int fill_deck(std::string fileName, unsigned int numberOfColumns);
        void loadFont();

        // Private members
        sf::RenderWindow mWindow;
        Character mPlayer;
        Character mEnemy;
        float mWindowWidth = 1920.f;
        float mWindowHeight = 1080.f;
        sf::View mView;
        std::vector<card> mDeck;
        sf::RectangleShape mCardShape;
        sf::Font mFont;
        sf::Text mCardText;

};

#endif // GAME_H header guard