// header file for MorseTreeNode
// Created by Kyngston Gaddy
// 03.24.2025

// import statements
#ifndef MORSETREENODE_H
#define MORSETREENODE_H

class MorseTreeNode {
    private:
        char sym;
        MorseTreeNode *left;
        MorseTreeNode *right;
public:
    MorseTreeNode();
    MorseTreeNode(char symbol);
    MorseTreeNode(const MorseTreeNode& other);
    ~MorseTreeNode();
    MorseTreeNode& operator=(const MorseTreeNode& other);
    char getSymbol() const;
    MorseTreeNode* getLeft() const;
    MorseTreeNode* getRight() const;
    void setSymbol(char symbol);
    void setLeft(MorseTreeNode* node);
    void setRight(MorseTreeNode* node);
};

#endif //MORSETREENODE_H
