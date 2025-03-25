// Implementation of MorseBST
// Created by Kyngston Gaddy
// 03.24.2025

//import statements
#include "MorseBST.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Description: default constructor
// Parameters: n/a
// Returns: n/a
MorseBST::MorseBST() {
    root = nullptr;
}

// Description: destructor
// Parameters: n/a
// Returns: n/a
MorseBST::~MorseBST() {
    if (root != nullptr) {
        deleteTree(root);
        root = nullptr;
    }
}

// Description: copy constructor
// Parameters: const MorseBST &other - the object being copied
// Returns: n/a
MorseBST::MorseBST(const MorseBST &other) {
    root = copyTree(other.root);
}

// Description: copy assignment operator
// Parameters: const MorseBST &other - the object being copied
// Returns: n/a
MorseBST &MorseBST::operator=(const MorseBST &other) {
    if (this != &other) {
        if (root != nullptr) {
            deleteTree(root);
            root = nullptr;
        }
        root = copyTree(other.root);
    }
    return *this;
}

// Description: builds the BST
// Parameters: none
// Returns: n/a
void MorseBST::buildMorseTree() {
    std::string filePath = "/Users/25gaddy/Desktop/ADV CS III/Projects/ADV3_Lab02.01/morsecode.txt";
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file..." << std::endl;
        return;
    }
    deleteTree(root);
    root = new MorseTreeNode();
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }
        std::istringstream iss(line);
        std::string word;
        char character;
        std::string morse;

        if (iss >> character >> morse) {
            character = toupper(character);
            MorseTreeNode* current = root;
            for (char dotDash : morse) {
                if (dotDash == '.') {
                    if (current ->getLeft() == nullptr) {
                        current->setLeft(new MorseTreeNode());
                    }
                    current = current->getLeft();
                }
                else if (dotDash == '-') {
                    if (current ->getRight() == nullptr) {
                        current->setRight(new MorseTreeNode());
                    }
                    current = current->getRight();
                }
            }
            current->setSymbol(character);
        }
    }
    file.close();
}

// Description: Converts a string of Morse code to readable text
// Parameters: morse - The Morse code string to convert
// Returns: The decoded text string
std::string MorseBST::morseToText(const std::string &morse) {
    std::string end;
    std::string currentMorse;
    std::string morseText = morse + "  ";
    int spaces = 0;
    bool hasValidCharacter = false;

    for (char character : morseText) {
        if (character == ' ') {
            spaces++;
            if (!currentMorse.empty()) {
                MorseTreeNode* current = root;
                bool valid = true;

                for (char dotDash : currentMorse) {
                    if (dotDash != '.' && dotDash != '-') {
                        valid = false;
                        break;
                    }
                    if (dotDash == '.') {
                        if (current == nullptr || current->getLeft() == nullptr) {
                            valid = false;
                            break;
                        }
                        current = current->getLeft();
                    }
                    else if (dotDash == '-') {
                        if (current == nullptr || current->getRight() == nullptr) {
                            valid = false;
                            break;
                        }
                        current = current->getRight();
                    }
                }
                if (valid && current != nullptr && current->getSymbol() != '\0') {
                    end += current->getSymbol();
                    hasValidCharacter = true;
                }
                else {
                    end += '*'; // not a valid key
                }
                currentMorse.clear();
            }
            if (spaces > 1) {
                if (hasValidCharacter) {
                    end += " ";
                }
                spaces = 0;
                hasValidCharacter = false;
            }
        }
        else if (character == '.' || character == '-') {
            currentMorse += character;
            spaces = 0;
        }
        else if (character != ' ') {
            currentMorse += '*';
        }
    }
    return end;
}

// Description: Converts a string of text code to readable morse code
// Parameters: text - The text string to convert to morse
// Returns: morse code
std::string MorseBST::textToMorse(const std::string &text) {
    std::string end;
    bool firstWord = true;
    std::istringstream iss(text);
    std::string word;

    while (iss >> word) {
        if (!firstWord) {
            end += "   ";
        }
        for (int i = 0; i < word.length(); i++) {
            char character = std::toupper(word[i]);
            if (character < 'A' || character > 'Z') {
                continue;
            }

            std::string morse;
            MorseTreeNode* current = root;
            bool found = false;
            findMorse(current, character, "", morse, found);

            if (!morse.empty()) {
                if (!end.empty() && end.back() != ' ') {
                    end += " ";
                }
                end += morse;
            }
        }
        firstWord = false;
    }
    return end;
}

// Description: searches to find the morse code for the given character
// Parameters: node, target, morse, end, found - uses the given node to search for the target character --> saves the morse code into the end result --> indicates if it's finished by changing the state of found
// Returns: n/a
void MorseBST::findMorse(MorseTreeNode *node, char target, const std::string &morse, std::string &end, bool &found) {
    if (node == nullptr || found) {
        return;
    }
    if (node->getSymbol() == target) {
        end = morse;
        found = true;
        return;
    }
    findMorse(node->getLeft(), target, morse + ".", end, found);
    findMorse(node->getRight(), target, morse + "-", end, found);
}

// Description: deletes a tree using recursion
// Parameters: node - the node that's being deleted
// Returns: n/a
void MorseBST::deleteTree(MorseTreeNode* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->getLeft());
    deleteTree(node->getRight());
    delete node;
}

// Description: creates a copy of the BST using recursion
// Parameters: node - the node being copied
// Returns: a copy of the node
MorseTreeNode* MorseBST::copyTree(MorseTreeNode *node) {
    if (node == nullptr) {
        return nullptr;
    }
    MorseTreeNode* newNode = new MorseTreeNode(node->getSymbol());
    newNode->setLeft(copyTree(node->getLeft()));
    newNode->setRight(copyTree(node->getRight()));
    return newNode;
}