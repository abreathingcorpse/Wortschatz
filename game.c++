#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#endif // DEBUG_H

#include "game.h++"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

Game::Game() : mWindow(sf::VideoMode(1920,1080),
            "Wortshatz Spiel"),
            mView(sf::FloatRect(0.f,0.f,mWindowWidth,mWindowHeight)) {
                mCardShape.setSize(sf::Vector2f(1000.f,400.f));
                mCardShape.setPosition(sf::Vector2f(350.f,500.f));
            }

void Game::loadFont() {
    std::string pathToFontFile = "./NotoSans-Regular.ttf";
    if (!mFont.loadFromFile(pathToFontFile))
        std::cerr << "Unable to load the font." << std::endl;
}

int Game::fill_deck(std::string fileName, unsigned int numberOfColumns = 6) {
    std::string line, value;
    std::vector<std::string> fileValues;

    std::fstream csvFile(fileName, std::fstream::in | std::fstream::out);

    if (!csvFile) {
        std::cerr << "Unable to open file!" << std::endl;
        return EXIT_FAILURE; // preprocessor variable
    }

    while (std::getline(csvFile, line)) {

        std::stringstream lineStream(line);

        while (std::getline(lineStream, value, ',')) {
            fileValues.push_back(value);
        }
    }

    int numberOfRows = fileValues.size() / numberOfColumns;
    // The loop begins at 1, since we are excluding the header
    for (std::vector<card>::size_type i = 1; i < numberOfRows; i++) {
        card currentCard;

        // It's * i, since that's the row I'm getting the card from
        currentCard.ID = std::stoul(fileValues[0+numberOfColumns*i]);
        currentCard.front = fileValues[1+numberOfColumns*i];
        currentCard.back = fileValues[2+numberOfColumns*i];
        currentCard.track = fileValues[3+numberOfColumns*i];
        currentCard.correct_cnt = fileValues[4+numberOfColumns*i];
        currentCard.incorrect_cnt = fileValues[5+numberOfColumns*i];

        mDeck.push_back(currentCard);
    }

    std::cout << mDeck[0].front << std::endl;

    csvFile.close();

    return 0;
}

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
//    mWindow.draw(mDeck[0]);
    mWindow.draw(mCardShape);
    mWindow.draw(mCardText);
    mWindow.display();
}

void Game::run() {
    loadFont();
//    mTestText.setFillColor(sf::Color::Red);
//    mTestText.setPosition(sf::Vector2f(10.f,10.f));
    fill_deck("test.csv");
    mCardText.setFont(mFont);
    mCardText.setString(mDeck[0].front);
    mCardText.setFillColor(sf::Color::Red);
    mCardText.setPosition(sf::Vector2f(350.f,500.f));
    mPlayer.loadSprite("player.png");
    mEnemy.loadSprite("slime.png");

    while(mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}