#pragma once

#include <unordered_set>
#include <vector>

class sudokuSquare
{
public:
    sudokuSquare();
    ~sudokuSquare();
    void resetSquare();

    void removePossibleValue(const int& val);
    void addPossibleValue(const int& val);
    void setOnlyValue(const int& val);
    std::vector<int> getPossibleValues();
    bool isPossibleValue(const int& val) const;
    bool isOnlyValue(const int& val) const;
    int countPossibleValues() const;

private:
    std::unordered_set<int> possibleValues;
    const std::vector<int> allValues{1,2,3,4,5,6,7,8,9};
};
