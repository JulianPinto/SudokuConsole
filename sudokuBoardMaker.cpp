#include "SudokuBoardMaker.h"
#include <deque>
#include <numeric>
#include <random>
#include <iostream>
#include <algorithm>

sudokuBoardMaker::sudokuBoardMaker(sudokuBoard* sudokuBoard) : boardPointer(sudokuBoard) {
    possibleValues = std::vector<std::vector<sudokuSquare>>(ROWS, std::vector<sudokuSquare>(COLS));
}

sudokuBoardMaker::~sudokuBoardMaker(){}

void sudokuBoardMaker::createSudokuBoard(const SudokuDifficulty & dif) {
    switch (dif)
    {
    case SudokuDifficulty::easy:
        makeBoard(30);
        break;
    case SudokuDifficulty::medium:
        makeBoard(25);
        break;
    case SudokuDifficulty::hard:
        makeBoard(20);
        break;
    }
}

void sudokuBoardMaker::makeBoard(const int & givenNumbers) {
    std::deque<int> coords(ROWS * COLS);
    std::iota(std::begin(coords), std::end(coords), 0);
    std::shuffle(std::begin(coords), std::end(coords), std::default_random_engine());

    for(int i = 0; i < givenNumbers; i++) {
        int r = coords.front() / ROWS;
        int c = coords.front() % ROWS;
        coords.pop_front();

        std::vector<int> coordValues = possibleValues[r][c].getPossibleValues();
        std::deque<int> values(std::begin(coordValues), std::end(coordValues));
        std::shuffle(std::begin(values), std::end(values), std::default_random_engine());

        while(!validInput(r, c, values.front())) {
            values.pop_front();

            // DEBUG
            if(values.size() < 1) {
                std::cout << "THIS METHOD OF MAKING BOARDS DOESNT WORK\n";
                return;
            }
        }
        setValue(r, c, values.front());
    }
}

void sudokuBoardMaker::setValue(const int & r, const int & c, const int & num) {
    boardPointer->at(r)[c] = num;
    possibleValues[r][c].setOnlyValue(num);
    removeValueFromRow(r, c, num);
    removeValueFromCol(r, c, num);
    removeValueFrom3x3(r, c, num);
}

void sudokuBoardMaker::removeValueFromRow(const int& r, const int& c, const int& num) {
    for(int i = 0; i < ROWS; i++) {
        if(i != r)
            possibleValues[i][c].removePossibleValue(num);
    }
}

void sudokuBoardMaker::removeValueFromCol(const int& r, const int& c, const int& num) {
    for(int i = 0; i < COLS; i++) {
        if(i != c)
            possibleValues[r][i].removePossibleValue(num);
    }
}

void sudokuBoardMaker::removeValueFrom3x3(const int& r, const int& c, const int& num) {
    int row = r / 3;
    int col = c / 3;

    for(int i = row * 3; i < (row + 1) * 3; i++) {
        for(int j = col * 3; j < (col + 1) * 3; j++) {
            if(i != r && j != c)
                possibleValues[r][i].removePossibleValue(num);
        }
    }
}

bool sudokuBoardMaker::validInput(const int & row, const int & col, const int & num) const {
    return validInRow(row, col, num) && validInCol(row, col, num) && validIn3x3(row, col, num);
}

bool sudokuBoardMaker::validInRow(const int & r, const int & c, const int & num) const {
    for(int i = 0; i < ROWS; i++) {
        if(i != r && possibleValues[i][c].isOnlyValue(num))
            return false;
    }
    return true;
}

bool sudokuBoardMaker::validInCol(const int & r, const int & c, const int & num) const {
    for(int i = 0; i < COLS; i++) {
        if(i != c && possibleValues[r][i].isOnlyValue(num))
            return false;
    }
    return true;
}

bool sudokuBoardMaker::validIn3x3(const int & r, const int & c, const int & num) const {
    int row = r / 3;
    int col = c / 3;

    for(int i = row * 3; i < (row + 1) * 3; i++) {
        for(int j = col * 3; j < (col + 1) * 3; j++) {
            if(i != r && j != c && possibleValues[i][j].isOnlyValue(num))
                return false;
        }
    }
    return true;
}