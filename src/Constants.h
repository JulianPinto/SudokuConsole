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

sudokuSquare& getSquareFrom1D(sudokuBoard& board, int& coord) {
    int row = coord / COLS;
    int col = coord % ROWS;
    return board[row][col];
}