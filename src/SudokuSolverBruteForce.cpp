#include "SudokuSolverBruteForce.h"

SudokuSolverBruteForce::SudokuSolverBruteForce() {}

SudokuSolverBruteForce::~SudokuSolverBruteForce(){}

bool SudokuSolverBruteForce::isCorrect(const sudokuBoard& board) {
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            if(board[r][c] != 0) {
                int num = board[r][c];
                if(isInvalidNumLocation(board, r, c, num)) {
                    correct = false;
                    return false;
                }
            }
        }
    }
    correct = true;
    return true;
}

bool SudokuSolverBruteForce::isInvalidNumLocation(const sudokuBoard & board, const int & r, const int & c, const int & num) {
    correct = validInput(board, r, c, num);
    return !correct;
}
