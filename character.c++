#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#endif // DEBUG_H

#include "character.h++"

void Character::loadSprite() {
    if (!mCharacterTexture.loadFromFile("art/character.png")) {
        std::cerr << "Failed to load the character texture." << std::endl;
    }

    mCharacterSprite.setTexture(mCharacterTexture);
}