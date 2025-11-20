// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 5 : Scare Games

#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <iostream>

// Monster class stores name and scream power of a monster
class Monster {
public:
    std::string name;       // Monster's name
    int screamPower;        // Monster's scream power level

    Monster();              // Default constructor
    Monster(std::string name, int power); // Constructor with values

    // Compare scream power (used to decide winners)
    bool operator>(const Monster& other) const;
    bool operator<(const Monster& other) const;

    // Check if two monsters are the same (name and power)
    bool operator==(const Monster& other) const;
    bool operator!=(const Monster& other) const;

    // Print monster info like "Mike (Power: 115)"
    friend std::ostream& operator<<(std::ostream& os, const Monster& m);
};

#endif
