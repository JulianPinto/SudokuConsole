#pragma once
#include "SudokuSolver.h"
#include "Constants.h"
#include <utility>
#include <queue>

class SudokuSolverBruteForce : public SudokuSolver {
public:
    SudokuSolverBruteForce();
    ~SudokuSolverBruteForce();

    bool isCorrect(const sudokuBoard& board) override;
    bool isInvalidNumLocation(const sudokuBoard& board, const int& r, const int& c, const int& num) override;
    int numUniqueSolutions(sudokuBoard& board) override;
private:
    int uniqueSolution(sudokuBoard& board, std::queue<std::pair<int, int>> emptySquares);
};
