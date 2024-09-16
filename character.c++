#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#endif // DEBUG_H

#include "character.h++"
#include <string>

void Character::loadSprite(std::string character_png) {
    if (!mCharacterTexture.loadFromFile("art/" + character_png)) {
        std::cerr << "Failed to load the character texture." << std::endl;
    }

    mCharacterSprite.setTexture(mCharacterTexture);

    mCharacterSprite.scale(4.f,4.f);
}