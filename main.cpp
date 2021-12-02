// Author: CyanCoding, Camden Mac Leod
// File created on Dec 2, 2021

#include <iostream>             // std::cout
#include <vector>               // std::vector
#include <filesystem>           // std::filesystem
#include <fstream>             // std::ifstream

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

    std::cout << "Hangman - a C++ project by CyanCoding." << std::endl;
    std::cout << "More categories coming soon!" << std::endl << std::endl;
    std::cout << "Please select a category:" << std::endl;
    std::cout << "1. Animals" << std::endl << std::endl;
    std::cout << "Category number > ";

    std::string input;
    std::cin >> input;

    std::vector<std::string> dictionary = getDictionary(std::stoi(input));

    for (std::string i : dictionary) {
        std::cout << i << std::endl;
    }

    return 0;
}
