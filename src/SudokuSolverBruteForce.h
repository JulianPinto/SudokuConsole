#pragma once
#include "SudokuSolver.h"
#include "Constants.h"
class SudokuSolverBruteForce : public SudokuSolver {
public:
    SudokuSolverBruteForce();
    ~SudokuSolverBruteForce();

    bool isCorrect(const sudokuBoard& board) override;
    bool isInvalidNumLocation(const sudokuBoard& board, const int& r, const int& c, const int& num) override;
    int numUniqueSolutions(sudokuBoard& board) override;
};
