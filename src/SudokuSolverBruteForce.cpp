#include "SudokuSolverBruteForce.h"

SudokuSolverBruteForce::SudokuSolverBruteForce() {}

SudokuSolverBruteForce::~SudokuSolverBruteForce(){}

bool SudokuSolverBruteForce::isCorrect(const sudokuBoard& board) {
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            int num = board[r][c].getDisplay();
            if(num != 0) {
                if(!isInvalidNumLocation(board, r, c, num)) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool SudokuSolverBruteForce::isInvalidNumLocation(const sudokuBoard & board, const int & r, const int & c, const int & num) {
    return validInput(board, r, c, num);

}

//TODO
int SudokuSolverBruteForce::numUniqueSolutions(sudokuBoard & board) {
    return 1;
}
