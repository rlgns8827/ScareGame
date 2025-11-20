// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 5 : Scare Games

#ifndef DOTFILEGENERATOR_METHODS_H
#define DOTFILEGENERATOR_METHODS_H

#include <fstream>
#include <iostream>
#include <string>
#include "TournamentNode.h"

// Helper function to write each node and its children to the DOT file
template <typename T>
int saveTreeAsDotHelper(TournamentNode<T>* node, std::ofstream& file, int& nodeID) {
    if (node == nullptr) return -1; // Skip if node is empty

    int currentID = nodeID++; // Give this node a unique ID

    // Write this node’s label with monster name and power
    file << "    node" << currentID << " [label=\""
         << node->winner->name << ", (Power: "
         << node->winner->screamPower << ")\"]\n";

    // Write the left child and draw an arrow if it exists
    int leftID = saveTreeAsDotHelper(node->left, file, nodeID);
    if (leftID != -1) {
        file << "    node" << currentID << " -> node" << leftID << ";\n";
    }

    // Write the right child and draw an arrow if it exists
    int rightID = saveTreeAsDotHelper(node->right, file, nodeID);
    if (rightID != -1) {
        file << "    node" << currentID << " -> node" << rightID << ";\n";
    }

    return currentID;
}

// Main function that saves the whole tree to a DOT file
template <typename T>
void saveTreeAsDot(const std::string& filename, TournamentNode<T>* rootNode) {
    std::ofstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return;
    }

    file << "digraph TournamentTree {\n"; // Start of DOT graph
    int nodeID = 0;
    saveTreeAsDotHelper(rootNode, file, nodeID); // Write the tree
    file << "}\n"; // End of DOT graph
    file.close();  
}

#endif 