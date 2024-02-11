#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>

#include "sudoku.h"

Sudoku::Sudoku(SudokuSolver* solver) : board(ROWS, std::vector<sudokuSquare>(COLS, 0)), solver(solver), boardMaker(&board) {}

Sudoku::~Sudoku() {}

void Sudoku::run() {
    while(1) {
        // system("clear");
        switch(state) {
            case State::mainMenu:
                mainMenu();
            break;
            case State::newBoard:
                newBoard();
            break;
            case State::playing:
                playBoard();
                checkBoardComplete();
            break;
            case State::creatingBoard:
                //TODO
            break;
            case State::settings:
                settings();
                break;
            case State::exit:
               printGoodbye();
               return;
            break;
        }
    }
}

void Sudoku::resetGrid() {
    for(auto& row : board) {
        for(auto& square : row) {
            square.resetSquare();
        }
    }
}

void Sudoku::setNumber(const int & r, const int & c, const int & num) {
    board[r][c].setDisplay(num);
}

void Sudoku::mainMenu() {
    printMenu();
    int option;
    std::cin >> option;
    switch(option) {
    case 1: // new board
        state = State::newBoard;
        break;
    case 2: // make board
        state = State::creatingBoard;
        break;
    case 3: // settings
        state = State::settings;
        break;
    case 4: // exit
        state = State::exit;
        break;
    default:
        std::cout << "Invalid input\n";
        break;
    }
}

void Sudoku::newBoard() {
    printNewBoardMenu();
    int option;
    std::cin >> option;
    switch (option) {
    case 1: // easy
        makeSudokuBoard(SudokuDifficulty::easy);
        state = State::playing;
        break;
    case 2: // medium
        makeSudokuBoard(SudokuDifficulty::medium);
        state = State::playing;
        break;
    case 3: // hard
        makeSudokuBoard(SudokuDifficulty::hard);
        state = State::playing;
        break;
    case 4: // back
        state = State::mainMenu;
        break;
    default:
        std::cout << "Invalid input\n";
        break;
    }
}

void Sudoku::playBoard() {
    printGrid();
    std::cout << "Enter the coordinates then the number to place at the coordinates.\nE.G. 0, 2, 2 would place a 2 at row 0 column 2\nOr enter 0 0 0 to exit the game\n";
    int r = -1, c = -1, num = -1;
    std::cin >> r >> c >> num;
    if(inputValid(r, c, num)) {
        processValidBoardInput(r, c, num);
    } else if(r == c == num == 0) {
        std::cout << "Exiting game\n";
        resetGrid();
        state = State::mainMenu;
    } else {
        std::cout << "invalid input\n";
    }
}

void Sudoku::settings() {
    printSettings();
    int option;
    std::cin >> option;
    switch (option) {
    case 1: // change error check
        errorCheck = !errorCheck;
        break;
    
    case 2: // exit
        state = State::mainMenu;
        break;

    default:
        std::cout << "invalid input\n";
    }
}

void Sudoku::makeSudokuBoard(const SudokuDifficulty& dif) {
    boardMaker.createSudokuBoard(dif);
}

void Sudoku::processValidBoardInput(const int& r, const int& c, const int& num) {
    std::cout << "Setting row " << r << " and column " << c << " to " << num << '\n';
    setNumber(r, c, num);
}

void Sudoku::printGrid() const {
    std::cout << "    0 1 2  3 4 5  6 7 8\n";
    for(int row = 0; row < ROWS; row++) {
        if(row % 3 == 0) printHorizontal();
        std::cout << row << ' ';
        for(int col = 0; col < COLS; col++) {
            if(col % 3 == 0) std::cout << '|';
            printNumber(col, row);
        }
        std::cout << "|\n";
    }
    printHorizontal();
}

void Sudoku::printNumber(const int& col, const int& row) const {
    if(board[col][row].isFixed()) {
        std::cout << CORRECT_COLOR << board[col][row] << RESET_COLOR;
    } else if(board[col][row].getDisplay() != 0) {
        std::cout << board[col][row].getDisplay();
    } else {
        std::cout << ' ';
    }
    std::cout << ' ';
}

void Sudoku::checkBoardComplete() {
    if(isBoardSolved()) {
        std::cout << "Congratulations!\nBoard has been solved\n";
        printGrid();
        state = State::mainMenu;
    }
}

bool Sudoku::isBoardValid() const {
    return solver->getCorrect();
}

bool Sudoku::isBoardSolved() const {
    bool solved = solver->isCorrect(board) && solver->isBoardComplete(board);
    return solved;
}

bool Sudoku::validNumber(const int& num) const {
    if(num > 0 && num <= 9)
        return true;
    return false;
}

bool Sudoku::validCoordinates(const int& row, const int& col) const {
    if(row < 0 || row > 9 || col < 0 || col > 9)
        return false;
    if(board[row][col].isFixed())
        return false;
    return true;
}

bool Sudoku::inputValid(const int& r, const int& c, const int& num) {
    if(!validNumber(num) || !validCoordinates(r, c)) {
        return false;
    }
}

int Sudoku::getRandomNumber() const {
    return rand() % 9;
}

void Sudoku::printMenu() const {
    std::cout << "Control Menu\n1: New Board\n2: Make Board\n3: Settings\n4: Exit\n";
}

void Sudoku::printSettings() const {
    std::cout << "Settings:\n";
    std::cout << "1: toggle Error Check: " << (errorCheck ? "True\n" : "False\n");
    std::cout << "2: Exit\n";
}

void Sudoku::printNewBoardMenu() const {
    std::cout << "New Board\n1: Easy\n2: Medium\n3: Hard\n4: Back\n";
}

void Sudoku::printHorizontal() const {
    std::cout << "  ----------------------\n";
}

void Sudoku::printGoodbye() const {
    std::cout << "Thank you for playing!\nSee you next time!\n";
}
