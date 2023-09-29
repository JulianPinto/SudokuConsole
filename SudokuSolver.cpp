#include "SudokuSolver.h"

bool SudokuSolver::getCorrect() const {
    return correct;
}

bool SudokuSolver::isBoardComplete(const sudokuBoard& board) {
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            if(board[r][c].value == 0) {
                return false;
            }
        }
    }
    return true;
}