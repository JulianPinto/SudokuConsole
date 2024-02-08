#pragma once

#include <vector>
#include <queue>
#include <random>
#include <algorithm>
#include <numeric>
#include <chrono>
#include "sudokuSquare.h"
#include "Constants.h"

namespace helpers {
    sudokuSquare& getSquareFrom1D(sudokuBoard& board, int& coord) {
        int row = coord / COLS;
        int col = coord % ROWS;
        return board[row][col];
    }

    std::queue<int> makeRandomNumberQueue(const int& start, const int &nums) {
        std::vector<int> indexes(nums);
        std::iota(std::begin(indexes), std::end(indexes), start);

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);
        std::shuffle(std::begin(indexes), std::end(indexes), e);

        std::queue<int> queue;
        for(int i = 0; i < indexes.size(); i++)
            queue.push(indexes[i]);
        return queue;
    }
}
