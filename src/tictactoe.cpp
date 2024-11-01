#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/misc.h"
#include "../include/colors.h"

char board[3][3] = {
    {'0', '0', '0'},
    {'0', '0', '0'},
    {'0', '0', '0'}
};

void showBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

static void showChooseDifficultyMenu() {
    std::cout << std::endl;
    std::cout << BOLDYELLOW << centerText("TicTacToe Game") << RESET << std::endl;
    std::cout << MAGENTA << centerText("Choose the difficulty:") << RESET << std::endl;
    std::cout << std::endl;
    std::cout << GREEN << "EASY [1]" << RESET << std::endl;
    std::cout << YELLOW << "MEDIUM [2]" << RESET << std::endl;
    std::cout << RED << "HARD [3]" << RESET << std::endl;
    std::cout << std::endl;
    std::cout << BLUE << "EXIT [0]" << RESET << std::endl;
    std::cout << std::endl;
}

int makeChoice(int min = 1, int max = 3) {
    int value = -1;
    std::cin >> value;
    while(value < min || value > max) {
        std::cout << RED << "Invalid value. Try again." << RESET << std::endl;
        std::cout << "Enter the value again: ";
        std::cin >> value;
    }
    return value;
}

bool validChoice(int row, int column) {
    return board[row][column] == '0';
}

static void startGame(int difficulty) {
    if(difficulty == 1) {
        bool stillPlayingFlag = true;

        while(stillPlayingFlag) {
            bool validChoiceFlag = false;

            while(!validChoiceFlag) {
                std::cout << std::endl;
                std::cout << GREEN << "Enter the row (1-3): " << RESET;
                int selectedRow = makeChoice(1, 3) - 1; // Convert to 0-based index

                std::cout << std::endl;
                std::cout << GREEN << "Enter the column (1-3): " << RESET;
                int selectedColumn = makeChoice(1, 3) - 1; // Convert to 0-based index

                // Validate the choice
                if(validChoice(selectedRow, selectedColumn)) {
                    validChoiceFlag = true;
                    board[selectedRow][selectedColumn] = 'X';
                } else {
                    std::cout << RED << "Invalid choice. Spot already taken. Try again." << RESET << std::endl;
                }
            }
            showBoard();
        }
    }
}

int startTicTacToeGame() {
    bool playAgain = true;

    while(playAgain) {
        srand(static_cast<unsigned int>(time(nullptr)));

        clearScreen();
        showChooseDifficultyMenu();
        std::cout << GREEN << "Enter your choice: " << RESET;
        int difficulty = makeChoice(0, 3);

        if (difficulty == 0) {
            return -1;
        }

        startGame(difficulty);

        std::cout << std::endl;
        std::cout << YELLOW << "Do you want to play again? [Y/N]: " << RESET;
        char choice;
        std::cin >> choice;

        if(!(choice == 'Y' || choice == 'y')) {
            std::cout << std::endl;
            std::cout << GREEN << "Goodbye!" << RESET << std::endl;
            playAgain = false;
        } else {
            // Reset the board for a new game
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    board[i][j] = '0';
        }
    }

    return 0;
}
