#pragma once
#include <vector>

enum class SudokuDifficulty: int {
    easy,
    medium,
    hard
};

typedef std::vector<std::vector<int>> sudokuBoard;
const int ROWS{9};
const int COLS{9};