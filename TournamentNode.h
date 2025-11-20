// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 5 : Scare Games

#ifndef TOURNAMENTNODE_H
#define TOURNAMENTNODE_H

// Template class for a node in the tournament tree
template <typename T>
class TournamentNode {
public:
    T* winner;                  // Pointer to the winner of this match
    TournamentNode<T>* left;   // Left child (first competitor or sub-match)
    TournamentNode<T>* right;  // Right child (second competitor or sub-match)

    // Constructor sets winner and initializes children to null
    TournamentNode(T* winner) : winner(winner), left(nullptr), right(nullptr) {}
};

#endif // TOURNAMENTNODE_H
