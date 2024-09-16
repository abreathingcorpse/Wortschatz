#include "game.h++"

Game::Game() : mWindow(sf::VideoMode(1920,1080),
            "Wortshatz Spiel") {}

void Game::processEvents() {
    sf::Event event;

    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Game::update() {
    mCharacter.mCharacterSprite.setPosition(sf::Vector2f(100.f,100.f));
}

void Game::render() {
    // empty for now
    mWindow.clear();
    mWindow.draw(mCharacter.mCharacterSprite);
    mWindow.display();
}

void Game::run() {
    mCharacter.loadSprite();

    while(mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}