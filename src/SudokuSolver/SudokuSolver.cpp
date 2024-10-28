#include "SudokuSolver.hpp"

bool SudokuSolver::isCorrect(const sudokuBoard& board) {
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            int num = board[r][c].getValue();
            if(num != 0) {
                if(!isInvalidNumLocation(board, r, c, num)) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool SudokuSolver::isBoardComplete(const sudokuBoard& board) {
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            if(board[r][c].getValue() == 0) {
                return false;
            }
        }
    }
    return true;
}

bool SudokuSolver::validInput(const sudokuBoard& board, const int& r, const int& c, const int& num) const {
    return validInRow(board, r, c, num) && validInCol(board, r, c, num) && validIn3x3(board, r, c, num);
}

bool SudokuSolver::validInRow(const sudokuBoard & board, const int & r, const int & c, const int & num) const {
    for(int i = 0; i < COLS; i++) {
        if(board[r][i].getValue() == num && i != c) {
            return false;
        }
    }
    return true;
}

bool SudokuSolver::validInCol(const sudokuBoard & board, const int & r, const int & c, const int & num) const {
    for(int i = 0; i < ROWS; i++) {
        if(board[i][c].getValue() == num && i != r) {
            return false;
        }
    }
    return true;
}

bool SudokuSolver::validIn3x3(const sudokuBoard & board, const int & r, const int & c, const int & num) const {
    int row = r / 3;
    int col = c / 3;

    for(int i = row * 3; i < (row + 1) * 3; i++) {
        for(int j = col * 3; j < (col + 1) * 3; j++) {
            if(board[i][j].getValue() == num && i != r && j != c) {
                return false;
            }
        }
    }
    return true;
}
