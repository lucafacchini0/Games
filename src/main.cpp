#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream> // Include for ifstream
#include <vector> // Include for vector
#include "games/hangman.h"

using std::string;

void displayMenu() {
    std::cout << "1. Play Hangman" << std::endl;
    std::cout << "2. Quit" << std::endl;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int choice = -1;

    while (choice < 1 || choice > 2) {
        displayMenu();
        std::cin >> choice;
    }

    switch (choice) {
        case 1: {
            int difficulty = -1;
            std::cout << "Choose the difficulty: " << std::endl;
            std::cout << "1. Easy" << std::endl;
            std::cout << "2. Medium" << std::endl;
            std::cout << "3. Hard" << std::endl;

            std::cin >> difficulty;

            while (difficulty < 1 || difficulty > 3) {
                std::cout << "Invalid. Try again" << std::endl;
                std::cin >> difficulty;
            }

            if (difficulty == 1) {
                std::ifstream easyWords("easyWords.txt");
                if (!easyWords.is_open()) {
                    std::cerr << "Error openinssss the file." << std::endl;
                    return 1; // Exit with error
                }

                std::vector<string> words;
                string line;

                // Read each line into a vector
                while (std::getline(easyWords, line)) {
                    words.push_back(line);
                }

                easyWords.close(); // Close the file

                if (words.empty()) {
                    std::cerr << "No words found in the file." << std::endl;
                    return 1; // Exit with error
                }

                // Get a random word
                int randomWordIndex = rand() % words.size();
                std::cout << "Random word index: " << randomWordIndex << std::endl;
                std::cout << "Random word: " << words[randomWordIndex] << std::endl;
            }
            break;
        }
        case 2:
            std::cout << "Quitting the game." << std::endl;
            break;
    }

    return 0; // Successful termination
}
