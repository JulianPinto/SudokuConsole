#pragma once
#include "SudokuSolver.h"
#include "Constants.h"
class SudokuSolverBruteForce : public SudokuSolver {
public:
    SudokuSolverBruteForce();
    ~SudokuSolverBruteForce();

    bool isCorrect(const sudokuBoard& board) override;
    bool isBoardSolved(const sudokuBoard& board) override;

private:
    bool isInvalidNumLocation(const sudokuBoard& board, const int& r, const int& c, const int& num);
    bool onlyNumInRow(const sudokuBoard& board, const int& r, const int& c, const int& num);
    bool onlyNumInCol(const sudokuBoard& board, const int& r, const int& c, const int& num);
    bool onlyNumIn3x3(const sudokuBoard& board, const int& r, const int& c, const int& num);
};
