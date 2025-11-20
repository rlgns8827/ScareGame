// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 5 : Scare Games

#ifndef TOURNAMENTTREE_CPP
#define TOURNAMENTTREE_CPP

#include "TournamentTree.h"
#include <algorithm>

// Constructor sets root to null
template <typename T>
TournamentTree<T>::TournamentTree() : root(nullptr) {}

// Destructor deletes the entire tree
template <typename T>
TournamentTree<T>::~TournamentTree() {
    destroyTree(root);
}

// Recursively delete all nodes in the tree
template <typename T>
void TournamentTree<T>::destroyTree(TournamentNode<T>* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node->winner;
        delete node;
    }
}

// Builds a basic single elimination bracket (no losers bracket)
template <typename T>
TournamentNode<T>* TournamentTree<T>::buildSingleElimination(std::vector<T*>& competitors) {
    std::vector<T*> dummy;
    return buildSingleEliminationWithLosers(competitors, dummy); // Reuses the more general method
}

// Builds a single elimination tree using round-based pairing (1v2, 3v4, etc.)
template <typename T>
TournamentNode<T>* TournamentTree<T>::buildSingleEliminationWithRounds(std::vector<T*>& competitors, std::vector<T*>& losers) {
    std::vector<TournamentNode<T>*> currentRound;

    // Create a leaf node for each monster
    for (auto& m : competitors)
        currentRound.push_back(new TournamentNode<T>(new T(*m)));

    // Repeat until only one winner remains
    while (currentRound.size() > 1) {
        std::vector<TournamentNode<T>*> nextRound;

        for (size_t i = 0; i < currentRound.size(); i += 2) {
            if (i + 1 == currentRound.size()) {
                nextRound.push_back(currentRound[i]); // Odd one out moves on
                continue;
            }

            TournamentNode<T>* left = currentRound[i];
            TournamentNode<T>* right = currentRound[i + 1];

            // Determine winner and loser based on scream power
            T* winner = (*left->winner > *right->winner) ? left->winner : right->winner;
            T* loser  = (*left->winner > *right->winner) ? right->winner : left->winner;

            // Save the loser for possible losers bracket
            losers.push_back(new T(*loser));

            // Create a match node with the winner
            TournamentNode<T>* match = new TournamentNode<T>(new T(*winner));
            match->left = left;
            match->right = right;

            nextRound.push_back(match);
        }

        currentRound = nextRound; // Advance to next round
    }

    return currentRound.empty() ? nullptr : currentRound.front();
}

// Same as single elimination, but keeps track of losers
template <typename T>
TournamentNode<T>* TournamentTree<T>::buildSingleEliminationWithLosers(std::vector<T*>& competitors, std::vector<T*>& losers) {
    if (competitors.empty()) return nullptr;
    return buildSingleEliminationWithRounds(competitors, losers);
}

// Builds a double elimination bracket
template <typename T>
TournamentNode<T>* TournamentTree<T>::buildDoubleElimination(std::vector<T*>& competitors, TournamentNode<T>*& losersRoot) {
    std::vector<T*> losers;

    // Build winners bracket and collect losers
    TournamentTree<T> winnersTree;
    TournamentNode<T>* winnersRoot = winnersTree.buildSingleEliminationWithLosers(competitors, losers);

    // Remove the grand winner from the losers list
    losers.erase(std::remove_if(losers.begin(), losers.end(), [&](T* m) {
        return *m == *(winnersRoot->winner);
    }), losers.end());

    // Build losers bracket with remaining losers
    TournamentTree<T> losersTree;
    std::vector<T*> dummy;
    losersRoot = losersTree.buildSingleEliminationWithLosers(losers, dummy);

    // Create final match between winners bracket champion and losers bracket champion
    T* finalWinner = (*winnersRoot->winner > *losersRoot->winner)
        ? new T(*winnersRoot->winner)
        : new T(*losersRoot->winner);

    TournamentNode<T>* finalMatch = new TournamentNode<T>(new T(*finalWinner));
    finalMatch->left = winnersRoot;
    finalMatch->right = losersRoot;

    return finalMatch; // Return the final combined tree (used for printing, not DOT)
}

#endif
