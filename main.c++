#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#endif // DEBUG_H
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include "game.h++"

//struct card {
//    unsigned long ID;
//    std::string front;
//    std::string back;
//    std::string track;
//    std::string correct_cnt;
//    std::string incorrect_cnt;
//};

// We pass the deck by reference, since we want to modify the actual object and not just a copy
int fill_deck(std::vector<card> &deck, std::string fileName, unsigned int numberOfColumns = 6) {

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

        deck.push_back(currentCard);
    }

    csvFile.close();

    return 0;
}

int main() {

    std::vector<card> deck;

//    fill_deck(deck, "test.csv");

//    std::cout << "seed type: " << typeid(time(0)).name() << std::endl;
    long seed = time(0);
//    std::cout << "seed type: " << typeid(seed).name() << std::endl;
    std::cout << "seed: " << seed << std::endl;
    // Since the engine generates the same sequence of numbers each time it's run
    // both the engine and the distribution should be static objects in order to retain
    // the state
//    static std::default_random_engine random_engine(time(0));
    static std::mt19937 random_engine(time(0)); // Uses the Mersenne Twister Engine instead of the default one
    static std::uniform_int_distribution<unsigned> uniform_distribution(0,deck.size()-1);
//    static std::uniform_int_distribution<unsigned> uniform_distribution(0,9);
    std::cout << "random: " << uniform_distribution(random_engine) << std::endl;

    Game game;
    game.run();

    return 0;
}