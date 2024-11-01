#include <iostream>
#include "../include/colors.h"
#include "../include/hangman.h"
#include "../include/misc.h"

const int TOTAL_GAMES = 1;


void displayMenu() {
    std::cout << std::endl;
    std::cout << BOLDYELLOW << centerText("FacchiniGames") << RESET << std::endl;
    std::cout << BLUE << centerText("v1.0") << RESET << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << "Choose an option" << RESET << std::endl;
    std::cout << std::endl;
    std::cout << BLUE << "1. " << RESET << "Hangman Game" << std::endl;
    std::cout << RED << "0. " << RESET << "Exit" << std::endl;
    std::cout << std::endl;
}

int main() {
    int choice = -1;
    bool play = true;

    while(play) {
        clearScreen();
        displayMenu();
        std::cout << GREEN << "Enter your choice: " << RESET;
        std::cin >> choice;
        std::cout << std::endl;

        while (choice < 0 || choice > TOTAL_GAMES) {
            clearScreen();
            displayMenu();
            std::cout << RED << "Invalid choice!" << RESET << std::endl;
            std::cout << GREEN << "Enter your choice: " << RESET;
            std::cin >> choice;
            std::cout << std::endl;
        }

        if(choice == 1) { startHangmanGame(); }
        if(choice == 0) {
            std::cout << GREEN << "Goodbye!" << RESET << std::endl;
            play = false;
        }

        // do you want to play another game?
        if(play) {
            std::cout << std::endl;
            std::cout << YELLOW << "Do you want to play another game? [Y/N]: " << RESET;
            char playAgain;
            std::cin >> playAgain;
            if(!(playAgain == 'Y' || playAgain == 'y')) {
                std::cout << std::endl;
                std::cout << GREEN << "Goodbye!" << RESET << std::endl;
                play = false;
            }
        }
    }
    return 0;
}


