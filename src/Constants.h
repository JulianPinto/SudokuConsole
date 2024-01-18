#pragma once
#include <vector>
#include "sudokuSquare.h"

enum class SudokuDifficulty: int {
    easy,
    medium,
    hard
};

typedef std::vector<std::vector<sudokuSquare>> sudokuBoard;
const int ROWS{9};
const int COLS{9};