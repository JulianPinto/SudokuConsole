#pragma once
#include "Constants.h"
#include "sudokuSquare.h"
#include <vector>

class sudokuBoardMaker
{
private:
    // std::vector<std::vector<sudokuSquare>> possibleValues;
    sudokuBoard* boardPointer;
    sudokuBoard starter;

public:
    sudokuBoardMaker(sudokuBoard* sudokuBoard);
    ~sudokuBoardMaker();

    void createSudokuBoard(const SudokuDifficulty& dif);

private:
    void makeBoard(const int& givenNumbers);
    void shuffleStarterBoard();
    void setValue(const int& r, const int& c, const int& num);

    void removeValueFromRow(const int& r, const int& c, const int& num);
    void removeValueFromCol(const int& r, const int& c, const int& num);
    void removeValueFrom3x3(const int& r, const int& c, const int& num);

    // bool validInput(const int& row, const int& col, const int& num) const;
    // bool validInRow(const int& r, const int& c, const int& num) const;
    // bool validInCol(const int &r, const int& c, const int& num) const;
    // bool validIn3x3(const int &r, const int& c, const int& num) const;
};
