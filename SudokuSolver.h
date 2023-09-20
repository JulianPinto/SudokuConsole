#pragma once
#include <vector>

class SudokuSolver {
public:
    virtual bool isCorrect(const std::vector<std::vector<int>>& board) = 0;
    virtual bool isBoardSolved(const std::vector<std::vector<int>>& board) = 0;
};
