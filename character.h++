#ifndef CHAR_H // CHAR_H header guard
#define CHAR_H

#ifndef SFML_H // SFML_H header guard
#define SFML_H
#include <SFML/Graphics.hpp>
#endif // SFML_H header guard

#include <string>

class Character {
    public:
        void loadSprite(std::string character_png);
        sf::Sprite mCharacterSprite;
    
    private:
        sf::Texture mCharacterTexture;
};

#endif // CHAR_H header guard