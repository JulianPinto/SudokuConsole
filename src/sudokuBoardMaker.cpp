#include "SudokuBoardMaker.h"
#include <queue>
#include <numeric>
#include <random>
#include <iostream>
#include <algorithm>

sudokuBoardMaker::sudokuBoardMaker(sudokuBoard* sudokuBoard) : boardPointer(sudokuBoard), starter(ROWS, std::vector<int>(COLS, 0)) {
    // for(int r = 0; r < ROWS; r++) {
    //     std::iota(std::begin(starter[r]), std::end(starter[r]), 1);
    //     std::rotate(starter[r].begin(), starter[r].begin() + ((3 * r) % ROWS) + (r / 3), starter[r].end());
    // }
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
    fillIndependentSubGrids();

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            setValue(i, j, starter[i][j]);
        }
    }
    // std::deque<int> coords(ROWS * COLS);
    // std::iota(std::begin(coords), std::end(coords), 0);
    // std::shuffle(std::begin(coords), std::end(coords), std::default_random_engine());

    // for(int i = 0; i < givenNumbers; i++) {
    //     int r = coords.front() / ROWS;
    //     int c = coords.front() % ROWS;
    //     coords.pop_front();

        // std::vector<int> coordValues = possibleValues[r][c].getPossibleValues();
        // std::deque<int> values(std::begin(coordValues), std::end(coordValues));
        // std::shuffle(std::begin(values), std::end(values), std::default_random_engine());

        // while(!validInput(r, c, values.front())) {
        //     values.pop_front();

        //     // DEBUG
        //     if(values.size() < 1) {
        //         std::cout << "THIS METHOD OF MAKING BOARDS DOESNT WORK\n";
        //         return;
        //     }
        // }
        // setValue(r, c, values.front());
    // }
}

void sudokuBoardMaker::fillIndependentSubGrids() {
    
}

void sudokuBoardMaker::shuffleStarterBoard() {
    for(int i = 0; i < 3; i++) {

        // std::shuffle(std::begin(starter), std::end(starter), std::default_random_engine());
        std::vector<int> vertSectionOrder = makeRandomIndexes(COLS / 3);
        for(auto& row : starter) {
            for(int sector = 0; sector < COLS / 3; sector++) {
                std::vector<int> vertInnerSectionOrder = makeRandomIndexes(COLS / 3);
                for(int c = 0; c < COLS / 3; c++) {
                    std::swap(row[sector * 3 + c], row[vertSectionOrder[sector] * 3 + vertInnerSectionOrder[c]]);
                }
            }
        }

        std::vector<int> horzSectionOrder = makeRandomIndexes(ROWS / 3);
        for(int c = 0; c < COLS; c++) {
            for(int sector = 0; sector < ROWS / 3; sector++) {
                std::vector<int> horzInnerSectionOrder = makeRandomIndexes(ROWS / 3);
                for(int r = 0; r < ROWS / 3; r++) {
                    std::swap(starter[sector * 3 + r][c], starter[vertSectionOrder[sector] * 3 + horzInnerSectionOrder[r]][c]);
                }
            }
        }
    }
}

void sudokuBoardMaker::randomFillSubMatrix(const int &row, const int &col) {
    auto randomSequence = makeRandomIndexes(9);
    std::queue<int> sequence(std::begin(randomSequence), std::end(randomSequence));
    for(int r = 0; r < 3; r++) {
        for(int c = 0; c < 3; c++) {
            starter[row * 3 + r][col * 3 + c] = sequence.top();
            sequence.pop();
        }
    }
}

std::vector<int> sudokuBoardMaker::makeRandomIndexes(const int &numIndex)
{
    std::vector<int> indexes(numIndex);
    std::iota(std::begin(indexes), std::end(indexes), 0);
    std::shuffle(std::begin(indexes), std::end(indexes), std::default_random_engine());
    return indexes;
}

void sudokuBoardMaker::setValue(const int & r, const int & c, const int & num) {
    boardPointer->at(r)[c] = num;
    // possibleValues[r][c].setOnlyValue(num);
    // removeValueFromRow(r, c, num);
    // removeValueFromCol(r, c, num);
    // removeValueFrom3x3(r, c, num);
}

// void sudokuBoardMaker::removeValueFromRow(const int& r, const int& c, const int& num) {
//     for(int i = 0; i < ROWS; i++) {
//         if(i != r)
//             possibleValues[i][c].removePossibleValue(num);
//     }
// }

// void sudokuBoardMaker::removeValueFromCol(const int& r, const int& c, const int& num) {
//     for(int i = 0; i < COLS; i++) {
//         if(i != c)
//             possibleValues[r][i].removePossibleValue(num);
//     }
// }

// void sudokuBoardMaker::removeValueFrom3x3(const int& r, const int& c, const int& num) {
//     int row = r / 3;
//     int col = c / 3;

//     for(int i = row * 3; i < (row + 1) * 3; i++) {
//         for(int j = col * 3; j < (col + 1) * 3; j++) {
//             if(i != r && j != c)
//                 possibleValues[r][i].removePossibleValue(num);
//         }
//     }
// }

// bool sudokuBoardMaker::validInput(const int & row, const int & col, const int & num) const {
//     return validInRow(row, col, num) && validInCol(row, col, num) && validIn3x3(row, col, num);
// }

// bool sudokuBoardMaker::validInRow(const int & r, const int & c, const int & num) const {
//     for(int i = 0; i < ROWS; i++) {
//         if(i != r && possibleValues[i][c].isOnlyValue(num))
//             return false;
//     }
//     return true;
// }

// bool sudokuBoardMaker::validInCol(const int & r, const int & c, const int & num) const {
//     for(int i = 0; i < COLS; i++) {
//         if(i != c && possibleValues[r][i].isOnlyValue(num))
//             return false;
//     }
//     return true;
// }

// bool sudokuBoardMaker::validIn3x3(const int & r, const int & c, const int & num) const {
//     int row = r / 3;
//     int col = c / 3;

//     for(int i = row * 3; i < (row + 1) * 3; i++) {
//         for(int j = col * 3; j < (col + 1) * 3; j++) {
//             if(i != r && j != c && possibleValues[i][j].isOnlyValue(num))
//                 return false;
//         }
//     }
//     return true;
// }