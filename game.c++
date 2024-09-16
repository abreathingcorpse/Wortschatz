#include "game.h++"

Game::Game() : mWindow(sf::VideoMode(1920,1080),
            "Wortshatz Spiel"),
            mView(sf::FloatRect(0.f,0.f,mWindowWidth,mWindowHeight)) {}

void Game::resizeToAspectRatio(float desired_aspect_ratio, float current_aspect_ratio) {
    // Window is wider than it should
    if (current_aspect_ratio > desired_aspect_ratio) {
        // setViewport is defined as a ratio of the window size
        // 1 - desired / current is the black gap. It's divided over 2, since that's the left where it'll start
        // desired over current is the actual width that you'll have
        mView.setViewport(sf::FloatRect((1.f - desired_aspect_ratio / current_aspect_ratio) / 2.f, 0.f,
                                        desired_aspect_ratio / current_aspect_ratio, 1.f));
    } else 
    // Window is taller than it should
    if ( current_aspect_ratio < desired_aspect_ratio) {
        mView.setViewport(sf::FloatRect(0.f, (1 - current_aspect_ratio / desired_aspect_ratio) / 2.f,
                                        1.f, current_aspect_ratio / desired_aspect_ratio));
    } else { mView.setViewport(sf::FloatRect(0.f,0.f,1.f,1.f));}
}

void Game::processEvents() {
    sf::Event event;

    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mWindow.close();
        if (event.type == sf::Event::Resized) {
            float desired_aspect_ratio = mWindowWidth / mWindowHeight;
            float current_aspect_ratio = static_cast<float>(event.size.width) / 
                                         static_cast<float>(event.size.height);

            resizeToAspectRatio(desired_aspect_ratio, current_aspect_ratio);
        }
    }
}

void Game::update() {
    mPlayer.mCharacterSprite.setPosition(sf::Vector2f(400.f,300.f));
    mEnemy.mCharacterSprite.setPosition(sf::Vector2f(1200.f,300.f));
}

void Game::render() {
    // empty for now
    mWindow.clear();
    mWindow.setView(mView);
    mWindow.draw(mPlayer.mCharacterSprite);
    mWindow.draw(mEnemy.mCharacterSprite);
    mWindow.display();
}

void Game::run() {
    mPlayer.loadSprite("player.png");
    mEnemy.loadSprite("slime.png");

    while(mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}