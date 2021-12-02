// Author: CyanCoding, Camden Mac Leod
// File created on Dec 2, 2021

#include <iostream>             // std::cout
#include <vector>               // std::vector
#include <filesystem>           // std::filesystem
#include <fstream>              // std::ifstream
#include <algorithm>            // ::tolower

std::vector<std::string> getDictionary(int input) {
    std::string dictionaryFile;
    switch (input) {
        case 1:
            dictionaryFile = std::filesystem::current_path() / "animals.txt";
        break;
    }

    std::vector<std::string> dictionary;


    std::string line;
    std::ifstream file(dictionaryFile);
    if (!file.is_open()) {
        std::cout << "Sorry, couldn't find that dictionary!" << std::endl;
        return dictionary;
    }

    while (getline(file, line)) {
        dictionary.push_back(line);
    }

    return dictionary;
}

int main() {
    srand(time(0)); // Used for random generation of numbers

    std::cout << "\033[2J\033[1;1H"; // Clears the screen in Linux and Windows
    std::cout << "Hangman - a C++ project by CyanCoding." << std::endl;
    std::cout << "More categories coming soon!" << std::endl << std::endl;
    std::cout << "Please select a category:" << std::endl;
    std::cout << "1. Animals" << std::endl << std::endl;
    std::cout << "Category number > ";

    std::string input;
    std::cin >> input;

    std::vector<std::string> dictionary = getDictionary(std::stoi(input));

    // Get the word to use and convert it to lowercase
    std::string selectedWord = dictionary[(rand() % dictionary.size() - 1)];
    transform(selectedWord.begin(), selectedWord.end(), selectedWord.begin(), ::tolower);

    int wordLength = selectedWord.size();

    // Used to represent the word
    std::string guess = "";
    for (int i = 0; i < wordLength; i++) {
        guess += "-";
    }

    int triesLeft = 8;
    std::string lettersUsed;
    // Our repetitive loop until they run out of guesses or win
    while (triesLeft != 0) {
        bool correctLetter = false;

        std::cout << "\033[2J\033[1;1H"; // Clears the screen in Linux and Windows
        std::cout << "Current progress: " << guess << std::endl;
        std::cout << "Attempts left: " << triesLeft << std::endl;
        std::cout << "Letters used: " << lettersUsed << std::endl;

        std::cout << std::endl << "Please enter a character to guess > ";

        char letter;
        std::cin >> letter;

        for (int i = 0; i < wordLength; i++) {
            if (selectedWord[i] == letter) {
                guess[i] = letter;
                correctLetter = true;
            }
        }

        // We don't penalize them if they guess something
        // they have already guessed before
        bool alreadyGuessed = false;
        for (char l : lettersUsed) {
            if (l == letter) {
                alreadyGuessed = true;
            }
        }
        if (!alreadyGuessed) {
            if (!correctLetter) {
                triesLeft--;
            }
            lettersUsed += letter;
        }

        if (guess == selectedWord) {
            triesLeft = 0;
        }
    }

    if (guess == selectedWord) {
        std::cout << std::endl << "Congratulations! You solved the word " << selectedWord << std::endl;
    }
    else {
        std::cout << std::endl << "Sorry! You failed. The word was " << selectedWord << std::endl;
    }


    return 0;
}
