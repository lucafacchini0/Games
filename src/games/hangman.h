#include <iostream>
#include <string>

using std::string;

class Hangman {
public:
    Hangman(string word) : word(word), wordCopy(word) {
        emptyWordCopy();
        maxLetters = word.length();
    }

    void emptyWordCopy() {
        for(int i = 0; i < wordCopy.length(); i++) {
            wordCopy[i] = '_';
        }
    }

    int guessLetter(char letter) {

        bool foundLetter = false;

        for(int i = 0; i < wordCopy.length(); i++) {
            if(wordCopy[i] == '_' && word[i] == letter) {
                wordCopy[i] = letter;
                foundLetter = true;
            }
        }

        if(hasWon()) { return -2; }

        if(foundLetter) { return 0; }

        return -1;
    }

    bool hasWon() {
        for(int i = 0; i < wordCopy.length(); i++) {
            if(wordCopy[i] == '_') { return false; }
        }

        return true;
    }

    void displayCurrentWord() { std::cout << wordCopy << std::endl; }
    void displayFullWord() { std::cout << word << std::endl; }

private:
    int letterCounter = 0;
    int maxLetters;
    string wordCopy;
    const string word;
};

//