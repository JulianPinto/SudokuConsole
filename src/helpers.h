#pragma once

#include <queue>
#include "sudokuSquare.h"
#include "Constants.h"

namespace helpers {
    sudokuSquare& getSquareFrom1D(sudokuBoard& board, const int& coord);
    std::queue<int> makeRandomNumberQueue(const int& start, const int &nums);
}
