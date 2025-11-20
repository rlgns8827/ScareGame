// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-04
// PA 5 : Scare Games

#ifndef TOURNAMENTTREE_H
#define TOURNAMENTTREE_H

#include <vector>
#include "Monster.h"
#include "TournamentNode.h"

// Template class to manage tournament logic for any type (e.g., Monster)
template <typename T>
class TournamentTree {
public:
    TournamentNode<T>* root; // Root node of the tournament tree (final winner)

    TournamentTree();        // Constructor
    ~TournamentTree();       // Destructor (cleans up the tree)

    // Build a single-elimination bracket (no losers bracket)
    TournamentNode<T>* buildSingleElimination(std::vector<T*>& competitors);

    // Build single-elimination and keep track of losers
    TournamentNode<T>* buildSingleEliminationWithLosers(std::vector<T*>& competitors, std::vector<T*>& losers);

    // Build full double-elimination bracket (returns final match node, sets losersRoot)
    TournamentNode<T>* buildDoubleElimination(std::vector<T*>& competitors, TournamentNode<T>*& losersRoot);

    // Recursively delete all nodes in the tree
    void destroyTree(TournamentNode<T>* node);

private:
    // Builds tournament tree round-by-round (1v2, 3v4, ...)
    TournamentNode<T>* buildSingleEliminationWithRounds(std::vector<T*>& competitors, std::vector<T*>& losers);
};

#include "TournamentTree.cpp" // (templated class, most compilers recommend putting all implementations in the header file, or including .cpp at the end of the .h) asked by ChatGpt

#endif
