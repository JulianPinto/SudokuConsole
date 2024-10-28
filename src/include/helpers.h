#pragma once

#include <queue>
#include "SudokuSquare.hpp"
#include "Constants.h"

namespace helpers {
    SudokuSquare& getSquareFrom1D(sudokuBoard& board, const int& coord);
    std::queue<int> makeRandomNumberQueue(const int& start, const int &nums);
}
