// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 5 : Scare Games

#include <iostream>
#include "RunScareGame.h"

int main(int argc, char* argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        std::cerr << "Usage: ./monster.exe <input_file> <single|double>\n";
        return 1;
    }

    std::string inputFile = argv[1]; // Input file with monster data
    std::string mode = argv[2];      // Tournament mode: "single" or "double"

    RunScareGame game;
    game.runTournament(inputFile, mode); // Launch the tournament

    return 0;
}
