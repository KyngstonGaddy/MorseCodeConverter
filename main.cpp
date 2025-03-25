// main method of the program
// Created by Kyngston Gaddy
// 03.24.2025

// import statements
#include <iostream>
#include <sstream>
#include "MorseTreeNode.h"
#include "MorseBST.h"

// main method
int main() {
    MorseBST bst;
    bst.buildMorseTree();
    std::string input;
    bool continueProgram = true;

    std::cout << "* MORSE CODE TRANSLATOR *" << std::endl;
    while (continueProgram) {
        try {
            std::cout << "Please select from the following menu options: "
                         "\n\t 1: Text to Morse"
                         "\n\t 2: Morse to Text"
                         "\n\t 3: Quit the program" << std::endl;
            std::cout << "Your selection: ";
            std::getline(std::cin, input);
            int choice = std::stoi(input);
            if (choice == 1) {
                std::cout << "\nInput Text: ";
                std::getline(std::cin, input);
                std::cout << input + " ==> " + bst.textToMorse(input) + "\n" << std::endl;
                continueProgram = true;
            }
            else if (choice == 2) {
                std::cout << "\nInput Morse: ";
                std::getline(std::cin, input);
                std::cout << input + " ==> " + bst.morseToText(input) + "\n" << std::endl;
                continueProgram = true;
            }
           else if (choice == 3) {
                std::cout << "\n* End of Program *" << std::endl;
                continueProgram = false;
            }
            else {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }
}