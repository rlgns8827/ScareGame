// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 5 : Scare Games

#ifndef RUNSCAREGAME_H
#define RUNSCAREGAME_H

#include <string>
#include "Monster.h"
#include "TournamentTree.h"
#include "TournamentNode.h"

// Template declaration for saving any tournament tree as a DOT file
template <typename T>
void saveTreeAsDot(const std::string& filename, TournamentNode<T>* rootNode);

// RunScareGame class handles setting up and running the tournament
class RunScareGame {
public:
    // This takes the input file and the mode ("single" or "double")
    void runTournament(const std::string& filename, const std::string& mode);
};

#endif // RUNSCAREGAME_H
