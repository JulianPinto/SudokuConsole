#include "SudokuBoardMaker.h"
#include "helpers.h"
#include <iostream>

sudokuBoardMaker::sudokuBoardMaker(sudokuBoard* sudokuBoard) : boardPointer(sudokuBoard) {}

sudokuBoardMaker::~sudokuBoardMaker(){}

void sudokuBoardMaker::createSudokuBoard() {
    fillIndependentSubGrids();
    fillBoard();
}

void sudokuBoardMaker::fillIndependentSubGrids() {
    randomFillSubMatrix(0, 0);
    randomFillSubMatrix(1, 1);
    randomFillSubMatrix(2, 2);
}

void sudokuBoardMaker::randomFillSubMatrix(const int &row, const int &col) {
    std::queue<int> sequence = helpers::makeRandomNumberQueue(1, 9);
    for(int r = 0; r < 3; r++) {
        for(int c = 0; c < 3; c++) {
            setValue(row * 3 + r, col * 3 + c, sequence.front());
            sequence.pop();
        }
    }
}

void sudokuBoardMaker::fillBoard() {
    std::queue<int> allSquares = helpers::makeRandomNumberQueue(0, ROWS * COLS);
    fillRemainingBoard(allSquares);
}

// TODO: change to use sudokuSolver to remove code duplication
bool sudokuBoardMaker::fillRemainingBoard(std::queue<int>& allSquares) {
    while(helpers::getSquareFrom1D(*boardPointer, allSquares.front()).getValue() != 0 && !allSquares.empty()) {
        allSquares.pop();
    }

    if(allSquares.empty())
        return true;

    std::queue<int> possibleValues = helpers::makeRandomNumberQueue(1, 9);
    const int currentSquareRow = allSquares.front() / COLS;
    const int currentSquareCol = allSquares.front() % COLS;
    while(!possibleValues.empty()) {
        if(validInput(currentSquareRow, currentSquareCol, possibleValues.front())) {
            setValue(currentSquareRow, currentSquareCol, possibleValues.front());
            bool valueWorks = fillRemainingBoard(allSquares);
            if(valueWorks) {
                return true;
            }
        }
        setValue(currentSquareRow, currentSquareCol, 0);
        possibleValues.pop();
    }
    allSquares.push(currentSquareRow * COLS + currentSquareCol);
    return false;
}

void sudokuBoardMaker::setValue(const int & r, const int & c, const int & num) {
    boardPointer->at(r).at(c) = num;
    boardPointer->at(r).at(c).setDisplay(num);
}

bool sudokuBoardMaker::validInput(const int & row, const int & col, const int & num) const {
    return validInRow(row, col, num) && validInCol(row, col, num) && validIn3x3(row, col, num);
}

bool sudokuBoardMaker::validInRow(const int & r, const int & c, const int & num) const {
    for(int i = 0; i < ROWS; i++) {
        if(i != r && (*boardPointer)[i][c].getValue() == num)
            return false;
    }
    return true;
}

bool sudokuBoardMaker::validInCol(const int & r, const int & c, const int & num) const {
    for(int i = 0; i < COLS; i++) {
        if(i != c && (*boardPointer)[r][i].getValue() == num)
            return false;
    }
    return true;
}

bool sudokuBoardMaker::validIn3x3(const int & r, const int & c, const int & num) const {
    int row = r / 3;
    int col = c / 3;

    for(int i = row * 3; i < (row + 1) * 3; i++) {
        for(int j = col * 3; j < (col + 1) * 3; j++) {
            if(i != r && j != c && (*boardPointer)[i][j].getValue() == num)
                return false;
        }
    }
    return true;
}