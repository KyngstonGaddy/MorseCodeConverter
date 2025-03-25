// Implementation of the MorseTreeNode class
// Created by Kyngston Gaddy
// 03.24.2025

// import statements
#include "MorseTreeNode.h"

// Description: default constructor for the MorseTreeNode
// Parameters: n/a
// Returns: n/a
MorseTreeNode::MorseTreeNode() {
    sym = '\0';
    left = nullptr;
    right = nullptr;
}

// Description: parameterized constructor for the MorseTreeNode
// Parameters: symbol - the character/symbol being stored in the node
// Returns: n/a
MorseTreeNode::MorseTreeNode(char symbol) {
    sym = symbol;
    left = nullptr;
    right = nullptr;
}

// Description: copy constructor for the MorseTreeNode
// Parameters: const MorseTreeNode &other - the object being copied
// Returns: n/a
MorseTreeNode::MorseTreeNode(const MorseTreeNode &other) {
    sym = other.sym;
    left = nullptr;
    right = nullptr;
}

// Description: destructor
// Parameters: n/a
// Returns: n/a
MorseTreeNode::~MorseTreeNode() {
    delete left;
    delete right;
    left = nullptr;
    right = nullptr;
}

// Description: copy assignment operator for the MorseTreeNode
// Parameters: const MorseTreeNode &other - object being copied
// Returns: reference to the new object
MorseTreeNode& MorseTreeNode::operator=(const MorseTreeNode &other) {
    if (this != &other) {
        sym = other.sym;
        delete left;
        delete right;
        left = nullptr;
        right = nullptr;
    }
    return *this;
}

// Description: gets the symbol in the node
// Parameters: n/a
// Returns: n/a
char MorseTreeNode::getSymbol() const{
    return sym;
}

// Description: points to the left of the node
// Parameters: n/a
// Returns: n/a
MorseTreeNode* MorseTreeNode::getLeft() const {
    return left;
}

// Description: points to the right of the node
// Parameters: n/a
// Returns: n/a
MorseTreeNode* MorseTreeNode::getRight() const {
    return right;
}

// Description: sets the symbol in the node
// Parameters: n/a
// Returns: n/a
void MorseTreeNode::setSymbol(char symbol) {
    sym = symbol;
}

// Description: sets the left of the node
// Parameters: n/a
// Returns: n/a
void MorseTreeNode::setLeft(MorseTreeNode* node) {
    left = node;
}

// Description: sets the right of the node
// Parameters: n/a
// Returns: n/a
void MorseTreeNode::setRight(MorseTreeNode* node) {
    right = node;
}
