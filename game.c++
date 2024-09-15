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
    // empty
}

void Game::render() {
    // empty for now
    mWindow.clear();
    mWindow.display();
}

void Game::run() {
    while(mWindow.isOpen()) {
        processEvents();
        // update();
        render();
    }
}