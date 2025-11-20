# ScareGame

#### Overview
This project is a C++ implementation of a Tournament Tree system for the Scare Games competition, supporting both single-elimination and double-elimination formats. Each competitor is represented as a Monster with a name and scream power level. The program builds tournament trees round-by-round, determines winners based on scream levels, and outputs the final structure as a DOT file for visualization. Input is taken from a text file containing monster data, and the program produces DOT graphs showing the full match progression.

#### Key features
- Monster Class: Represents each competitor with a name and scream power. Implements comparison operators for determining match winners.
- TournamentNode Class: Represents a single match in the tournament, storing pointers to the winning Monster and its left/right child match nodes.
- TournamentTree Class:
    - Builds complete tournament structures for single- and double-elimination formats.
    - Handles uneven rounds by promoting unmatched competitors to the next round.
    - Maintains a losers’ bracket for double-elimination tournaments.
    - Produces a final champion by matching the winners’ bracket champion agains the losers’ bracket champion.
- DOT File Generation: Uses the provided DOTFileGeneratorMethods.cpp methods to output a .dot graph of the tournament structure.
- RunScareGame Class:
    - Handles file input, processing, formatting, and tournament execution.
    - Implements the runTournament() method called by main.
- Console-Based Simulation:
    - Supports both tournament modes via command-line arguments.
    - Reads monster data from a text file.
    - Saves DOT output to a specified file for visualization using Graphviz.

#### How to Run
To compile and run the program:

1. **Compile**: Use g++ to compile all project source file.
   ```bash
   g++ *.cpp -o monster.exe
   ```

2. **Run**: Run with single elimination.
   ```bash
   ./monster.exe monsters.txt single
   ```

3. **Run**: # Run with double elimination
   ```bash
   ./monster.exe monsters.txt double
   ```
   
#### Requirements
- C++ compiler (tested with g++)
- Text editor or IDE (e.g., VSCode) for code editing
- Terminal or command prompt for running compiled executable

#### References
- No external libraries or non-primitive data structures (e.g., vectors) are used, as per project requirements.


            
