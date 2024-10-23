#pragma once

#include <queue>
#include "sudokuSquare.hpp"
#include "Constants.h"

namespace helpers {
    sudokuSquare& getSquareFrom1D(sudokuBoard& board, const int& coord);
    std::queue<int> makeRandomNumberQueue(const int& start, const int &nums);
}
