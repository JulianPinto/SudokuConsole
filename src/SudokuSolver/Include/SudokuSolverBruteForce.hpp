#pragma once
#include "SudokuSolver.hpp"
#include "Constants.hpp"
#include <utility>
#include <queue>

class SudokuSolverBruteForce : public SudokuSolver {
public:
    SudokuSolverBruteForce();
    ~SudokuSolverBruteForce();

    bool isInvalidNumLocation(const sudokuBoard& board, const int& r, const int& c, const int& num) override;
    bool uniqueSolution(sudokuBoard& board) override;
private:
    int multiSolution(sudokuBoard& board, std::queue<std::pair<int, int>> emptySquares);
};
