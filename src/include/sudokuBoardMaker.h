#pragma once
#include "Constants.h"
#include "SudokuSquare.hpp"
#include <vector>
#include <queue>

class sudokuBoardMaker
{
private:
    sudokuBoard* boardPointer;

public:
    sudokuBoardMaker(sudokuBoard* sudokuBoard);
    ~sudokuBoardMaker();

    void createSudokuBoard();

private:
    void fillIndependentSubGrids();
    void fillBoard();
    bool fillRemainingBoard(std::queue<int>& allSquares);
    void randomFillSubMatrix(const int& r, const int& c);
    void setValue(const int& r, const int& c, const int& num);

    bool validInput(const int& row, const int& col, const int& num) const;
    bool validInRow(const int& r, const int& c, const int& num) const;
    bool validInCol(const int &r, const int& c, const int& num) const;
    bool validIn3x3(const int &r, const int& c, const int& num) const;
};
