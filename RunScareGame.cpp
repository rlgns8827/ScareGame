// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 5 : Scare Games

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "RunScareGame.h"
#include "DOTFileGeneratorMethods.h"

void RunScareGame::runTournament(const std::string& filename, const std::string& mode) {
    std::ifstream infile(filename.c_str()); // Open the input file
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    std::vector<Monster*> competitors; // Stores all monsters
    std::string line;

    // Read each line from the input file
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string name;
        int power;

        // Split line into name and scream power
        if (std::getline(ss, name, ',') && ss >> power) {
            name.erase(name.find_last_not_of(" \t\r\n") + 1); // Trim whitespace
            competitors.push_back(new Monster(name, power)); // Add monster to list
        }
    }

    infile.close(); // Done reading file

    TournamentTree<Monster> tree;
    TournamentNode<Monster>* root = nullptr;        // Final champion match node
    TournamentNode<Monster>* losersRoot = nullptr;  // Losers bracket root (if double elimination)

    // Run single-elimination tournament
    if (mode == "single") {
        root = tree.buildSingleElimination(competitors);
        saveTreeAsDot("winners_bracket.dot", root); // Save tree to DOT file
    }

    // Run double-elimination tournament
    else if (mode == "double") {
        root = tree.buildDoubleElimination(competitors, losersRoot);
        saveTreeAsDot("winners_bracket.dot", root);      // Full final tree
        saveTreeAsDot("losers_bracket.dot", losersRoot); // Losers bracket only
    }

    // Invalid tournament type
    else {
        std::cerr << "Invalid mode. Use 'single' or 'double'.\n";
        return;
    }

    // Output final winner
    std::cout << "Tournament completed. DOT files generated.\n";
    std::cout << "Champion: " << *(root->winner) << std::endl;
}
