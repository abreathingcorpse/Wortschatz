#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

struct card {
    unsigned long ID;
    std::string front;
    std::string back;
    std::string track;
    std::string correct_cnt;
    std::string incorrect_cnt;
};

int main() {

    std::string line, value;
    std::vector<std::string> fileValues;
//    unsigned long rowIndex = 0;
    unsigned int numberOfColumns = 6;

    //std::fstream csvFile("test.csv", std::fstream::ate | std::fstream::in | std::fstream::out);
    std::fstream csvFile("test.csv", std::fstream::in | std::fstream::out);

    if (!csvFile) {
        std::cerr << "Unable to open file!" << std::endl;
        return EXIT_FAILURE; // preprocessor variable
    }

//    // csvFile opened in ate mode, so it starts positioned at the end
//    auto end_mark = csvFile.tellg(); // current position of the marker
//    csvFile << "Write test.";


 //   std::cout << "First rowIndex: " << rowIndex << std::endl;

    while (std::getline(csvFile, line)) {

//        std::cout << line << std::endl;

        std::stringstream lineStream(line);

        while (std::getline(lineStream, value, ',')) {
//            std::cout << value << std::endl;
            fileValues.push_back(value);
        }

        
//        currentCard.ID = std::stoul(rowValues[0]);
//        if (rowIndex > 0)
//            std::cout << rowValues[0] << std::endl;
//        std::cout << currentCard.ID << std::endl;

//        ++rowIndex;
//        std::cout << "rowIndex within loop: " << rowIndex << std::endl;

    }

    card currentCard;
    currentCard.ID = std::stoul(fileValues[0+numberOfColumns]);
    std::cout << currentCard.ID << std::endl;
    currentCard.front = fileValues[1+numberOfColumns];
    currentCard.back = fileValues[2+numberOfColumns];
    currentCard.track = fileValues[3+numberOfColumns];
    currentCard.correct_cnt = fileValues[4+numberOfColumns];
    currentCard.incorrect_cnt = fileValues[5+numberOfColumns];

    std::cout << currentCard.front << std::endl;
    std::cout << currentCard.back << std::endl;
    std::cout << currentCard.track << std::endl;
    std::cout << currentCard.correct_cnt << std::endl;
    std::cout << currentCard.incorrect_cnt << std::endl;

    csvFile.close();

    return 0;
}