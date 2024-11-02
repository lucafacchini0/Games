#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "../include/misc.h"
#include "../include/colors.h"

char board[3][3] = {
    {'0', '0', '0'},
    {'0', '0', '0'},
    {'0', '0', '0'}
};

// Function to check if the chosen cell is valid
int validChoice(int row, int column) {
    if (board[row][column] == '0') {
        return 0; // Valid choice
    }

    return -1; // Invalid choice

}

// Function to display the Tic Tac Toe board
void showBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '0') {
                std::cout << "   ";
            } else if (board[i][j] == 'X') {
                std::cout << GREEN << " X " << RESET;
            } else if (board[i][j] == 'O') {
                std::cout << RED << " O " << RESET;
            }
            if (j < 2) std::cout << "|";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---|---|---" << std::endl;
    }
}

// Menu for choosing the difficulty level
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

// Function to make a choice with input validation
int makeChoice(int min = 1, int max = 3) {
    int value = -1;
    std::cin >> value;
    while (value < min || value > max) {
        std::cout << RED << "Invalid value. Try again." << RESET << std::endl;
        std::cout << "Enter the value again: ";
        std::cin >> value;
    }
    return value;
}

// Function for the computer's turn
void computerTurn(int difficulty) {
    if (difficulty == 1) {
        bool validChoiceFlag = false;
        while (!validChoiceFlag) {
            int selectedRow = rand() % 3;
            int selectedColumn = rand() % 3;
            if (validChoice(selectedRow, selectedColumn) == 0) {
                validChoiceFlag = true;
                board[selectedRow][selectedColumn] = 'O';
            }
        }
    }
}

// Function to check if a player has won
static bool hasWon() {
    // Check for a win in rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != '0') {
            return true;
        }
    }

    // Check for a win in columns
    for (int column = 0; column < 3; column++) {
        if (board[0][column] == board[1][column] && board[1][column] == board[2][column] && board[0][column] != '0') {
            return true;
        }
    }

    // Check for a diagonal win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '0') {
        return true;
    }

    // Check for an inverse diagonal win
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '0') {
        return true;
    }

    return false;
}

// Function to start the game
static void startGame(int difficulty) {
    bool stillPlayingFlag = true;
    while (stillPlayingFlag) {
        bool validChoiceFlag = false;
        showBoard();

        // Player's turn
        while (!validChoiceFlag) {
            std::cout << std::endl;
            std::cout << GREEN << "Enter the row (1-3): " << RESET;
            int selectedRow = makeChoice(1, 3) - 1; // Convert to 0-based index

            std::cout << std::endl;
            std::cout << GREEN << "Enter the column (1-3): " << RESET;
            int selectedColumn = makeChoice(1, 3) - 1; // Convert to 0-based index

            if (validChoice(selectedRow, selectedColumn) == 0) {
                validChoiceFlag = true;
                board[selectedRow][selectedColumn] = 'X';
            } else {
                std::cout << RED << "Invalid choice. Try again." << RESET << std::endl;
            }
        }

        // Check if the player has won
        if (hasWon()) {
            showBoard();
            std::cout << GREEN << "You won!" << RESET << std::endl;
            break;
        }

        // Computer's turn
        computerTurn(difficulty);
        if (hasWon()) {
            showBoard();
            std::cout << RED << "Computer wins!" << RESET << std::endl;
            break;
        }
    }
}

// Function to start the Tic Tac Toe game
int startTicTacToeGame() {
    bool playAgain = true;
    while (playAgain) {
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

        if (!(choice == 'Y' || choice == 'y')) {
            std::cout << std::endl;
            std::cout << GREEN << "Goodbye!" << RESET << std::endl;
            playAgain = false;
        } else {
            // Reset the board for a new game
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    board[i][j] = '0';
        }
    }
    return 0;
}
