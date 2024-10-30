#include <iostream>
#include "games/hangman.h"

int main() {
    Hangman firstWord = Hangman("Helicopter");

    char ch;
    int maxTries = 10;

    firstWord.displayCurrentWord();


    for(int i = 0; i < maxTries;) {
        std::cout << "Remaining tries: " << maxTries - i << std::endl;
        std::cout << "Insert a letter: " << std::endl;
        std::cin >> ch;

        int status = firstWord.guessLetter(ch);

        if(status == 0) {
            firstWord.displayCurrentWord();
            continue;
        } else if(status == -1) {
            std::cout << "No!" << std::endl;
            firstWord.displayCurrentWord();
            i++;
        } else if(status == -2) {
            std::cout << "You won!!" << std::endl;
            std::cout << "The word was: " << std::endl;
            firstWord.displayFullWord();

            break;
        }


    }
}
