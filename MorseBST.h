// header file for the MorseBST class
// Created by Kyngston Gaddy
// 03.24.2025

// import statements
#include <string>
#include "MorseTreeNode.h"

class MorseBST {
    public:
        MorseBST(); // Default constructor
        ~MorseBST(); // Destructor
        MorseBST(const MorseBST& other); // Copy constructor
        MorseBST& operator=(const MorseBST& other); // Copy assignment operator
        void buildMorseTree(); // Builds a Morse Code BST
        std::string morseToText(const std::string& morse);// Converts Morse code to text
        std::string textToMorse(const std::string& text); // Converts text to Morse code
        void findMorse(MorseTreeNode* node, char target, const std::string& morse, std::string& end, bool& found);
        void deleteTree(MorseTreeNode* node);
        MorseTreeNode* copyTree(MorseTreeNode* node);
    private:
        MorseTreeNode* root;
};
