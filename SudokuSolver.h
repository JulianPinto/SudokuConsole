#pragma once
#include <vector>
#include "Constants.h"

class SudokuSolver {
public:
    virtual bool isCorrect(const sudokuBoard& board) = 0;
    virtual bool isBoardSolved(const sudokuBoard& board) = 0;
    virtual bool isInvalidNumLocation(const sudokuBoard& board, const int& r, const int& c, const int& num) = 0;

    bool getCorrect() const;
protected:
    bool correct{false};
};
