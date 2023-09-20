#pragma once
#include "SudokuSolver.h"

class SudokuSolverBruteForce : public SudokuSolver {
public:
    SudokuSolverBruteForce();
    ~SudokuSolverBruteForce();

    bool isCorrect(const std::vector<std::vector<int>>& board) override;
    bool isBoardSolved(const std::vector<std::vector<int>>& board) override;
};
