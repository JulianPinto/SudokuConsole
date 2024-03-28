#pragma once
#include "SudokuSolver.h"
#include "Constants.h"
#include <utility>
#include <queue>

class SudokuSolverHuman : public SudokuSolver {
public:
    SudokuSolverHuman();
    ~SudokuSolverHuman();

    bool isCorrect(const sudokuBoard& board) override;
    bool isInvalidNumLocation(const sudokuBoard& board, const int& r, const int& c, const int& num) override;
    bool uniqueSolution(sudokuBoard& board) override;
private:
};
