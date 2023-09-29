#include "sudokuSquare.h"

sudokuSquare::sudokuSquare() {
    possibleValues = std::unordered_set<int>(std::begin(allValues), std::end(allValues));
}

sudokuSquare::~sudokuSquare() {}

void sudokuSquare::removePossibleValue(const int & val) {
    possibleValues.erase(val);
}

void sudokuSquare::addPossibleValue(const int & val) {
    possibleValues.insert(val);
}

inline bool sudokuSquare::isPossibleValue(const int & val) {
    return possibleValues.count(val);
}

void sudokuSquare::resetSquare() {
    value = 0;
    possibleValues.insert(std::begin(allValues), std::end(allValues));
}
