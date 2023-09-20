#include "SudokuSolverBruteForce.h"

bool SudokuSolverBruteForce::isCorrect(const sudokuBoard& board) {
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            if(board[r][c] != 0) {
                int num = board[r][c];
                if(isInvalidNumLocation(board, r, c, num))
                    return false;
            }
        }
    }
    return true;
}

bool SudokuSolverBruteForce::isBoardSolved(const sudokuBoard& board) {
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            int num = board[r][c];
            if(num == 0) return false;
            if(isInvalidNumLocation(board, r, c, num)) return false;
        }
    }
    return true;
}

bool SudokuSolverBruteForce::isInvalidNumLocation(const sudokuBoard & board, const int & r, const int & c, const int & num) {
    return !onlyNumInRow(board, r, c, num) || !onlyNumInCol(board, r, c, num) || !onlyNumIn3x3(board, r, c, num);
}

bool SudokuSolverBruteForce::onlyNumInRow(const sudokuBoard & board, const int & r, const int & c, const int & num) {
    for(int i = 0; i < ROWS; i++) {
        if(board[i][c] == num && i != r)
            return false;
    }
    return true;
}

bool SudokuSolverBruteForce::onlyNumInCol(const sudokuBoard & board, const int & r, const int & c, const int & num) {
    for(int i = 0; i < COLS; i++) {
        if(board[r][i] == num && i != c)
            return false;
    }
    return true;
}

bool SudokuSolverBruteForce::onlyNumIn3x3(const sudokuBoard & board, const int & r, const int & c, const int & num) {
    int row = r / 3;
    int col = c / 3;

    for(int i = row * 3; i < (row + 1) * 3; i++) {
        for(int j = col * 3; j < (col + 1) * 3; j++) {
            if(board[i][j] == num && i != r && j != c)
                return false;
        }
    }
    return true;
}
