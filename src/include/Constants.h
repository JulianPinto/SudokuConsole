#pragma once
#include <vector>
#include "SudokuSquare.hpp"


enum class SudokuDifficulty: int {
    easy = 35,
    medium = 30,
    hard = 25
};

typedef std::vector<std::vector<SudokuSquare>> sudokuBoard;
const int ROWS{9};
const int COLS{9};
