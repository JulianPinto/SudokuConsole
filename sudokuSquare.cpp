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

void sudokuSquare::setOnlyValue(const int & val) {
    possibleValues.clear();
    possibleValues.insert(val);
}

std::vector<int> sudokuSquare::getPossibleValues() {
    return std::vector<int>(possibleValues.begin(), possibleValues.end());
}

bool sudokuSquare::isPossibleValue(const int & val) const {
    return possibleValues.count(val);
}

bool sudokuSquare::isOnlyValue(const int & val) const {
    return countPossibleValues() == 1 && isPossibleValue(val);
}

int sudokuSquare::countPossibleValues() const {
    return possibleValues.size();
}

void sudokuSquare::resetSquare() {
    possibleValues.insert(std::begin(allValues), std::end(allValues));
}
