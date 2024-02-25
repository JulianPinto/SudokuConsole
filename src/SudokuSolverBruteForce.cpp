#include "SudokuSolverBruteForce.h"
#include "helpers.h"

SudokuSolverBruteForce::SudokuSolverBruteForce(){}

SudokuSolverBruteForce::~SudokuSolverBruteForce(){}

bool SudokuSolverBruteForce::isCorrect(const sudokuBoard& board) {
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

bool SudokuSolverBruteForce::isInvalidNumLocation(const sudokuBoard & board, const int & r, const int & c, const int & num) {
    return validInput(board, r, c, num);
}

bool SudokuSolverBruteForce::uniqueSolution(sudokuBoard& board) {
    if(!isCorrect(board))
        return false;
    std::queue<std::pair<int, int>> emptySquares;
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            if(board[r][c].getValue() == 0)
                emptySquares.push(std::pair<int,int>(r,c));
        }
    }
    int solutions = numSolutions(board, emptySquares);
    return solutions == 1;
}

int SudokuSolverBruteForce::numSolutions(sudokuBoard& board, std::queue<std::pair<int, int>> emptySquares) {
    if(emptySquares.empty()) {
        return 1;
    }

    int solutions = 0;
    std::queue<int> possibleValues = helpers::makeRandomNumberQueue(1, 9);
    int row = emptySquares.front().first;
    int col = emptySquares.front().second;
    emptySquares.pop();
    sudokuSquare& current = board[row][col];

    while(!possibleValues.empty()) {
        if(validInput(board, row, col, possibleValues.front())) {
            current.setValue(possibleValues.front());
            solutions += numSolutions(board, emptySquares);
            current.setValue(0);
        }
        possibleValues.pop();
    }
    return solutions;
}
