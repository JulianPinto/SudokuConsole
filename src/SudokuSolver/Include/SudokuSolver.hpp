#pragma once
#include <vector>
#include "Constants.hpp"

class SudokuSolver {
public:
    virtual bool isInvalidNumLocation(const sudokuBoard& board, const int& r, const int& c, const int& num) = 0;
    virtual bool uniqueSolution(sudokuBoard& board) = 0;

    virtual bool isCorrect(const sudokuBoard& board);
    bool isBoardComplete(const sudokuBoard& board);

    bool validInput(const sudokuBoard& board, const int& r, const int& c, const int& num) const;
    bool validInRow(const sudokuBoard& board, const int& r, const int& c, const int& num) const;
    bool validInCol(const sudokuBoard& board, const int& r, const int& c, const int& num) const;
    bool validIn3x3(const sudokuBoard& board, const int& r, const int& c, const int& num) const;
};
