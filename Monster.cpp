// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-03
// PA 5 : Scare Games

#include "Monster.h"

// Default constructor initializes an empty Monster
Monster::Monster() : name(""), screamPower(0) {}

// Parameterized constructor to create a Monster with a given name and scream power
Monster::Monster(std::string name, int power) : name(name), screamPower(power) {}

// Overload '>' operator to compare Monsters by screamPower
bool Monster::operator>(const Monster& other) const {
    return screamPower > other.screamPower;
}

// Overload '<' operator to compare Monsters by screamPower
bool Monster::operator<(const Monster& other) const {
    return screamPower < other.screamPower;
}

// Overload '==' to check if two Monsters are equal by name and screamPower
bool Monster::operator==(const Monster& other) const {
    return name == other.name && screamPower == other.screamPower;
}

// Overload '!=' to check inequality between two Monsters
bool Monster::operator!=(const Monster& other) const {
    return !(*this == other); // Reuses the '==' implementation
}

// Overload '<<' to allow printing Monster using std::cout << monster
std::ostream& operator<<(std::ostream& os, const Monster& m) {
    os << m.name << " (Power: " << m.screamPower << ")";
    return os;
}
