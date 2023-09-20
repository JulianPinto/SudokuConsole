#pragma once
#include <vector>
#include "Constants.h"

class SudokuSolver {
public:
    virtual bool isCorrect(const sudokuBoard& board) = 0;
    virtual bool isBoardSolved(const sudokuBoard& board) = 0;
};
