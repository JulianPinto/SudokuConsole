#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <algorithm>

#include "sudoku.h"

Sudoku::Sudoku(SudokuSolver* solver) : grid(ROWS, std::vector<int>(COLS, 0)), solver(solver) {}

Sudoku::~Sudoku() {}

void Sudoku::run() {
    while(1) {
        system("clear");
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
    for(auto& row : grid) {
        std::fill(row.begin(), row.end(), 0);
    }
}

void Sudoku::setNumber(const int & r, const int & c, const int & num) {
    grid[r][c] = num;
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
        makeRandomBoard(30);
        state = State::playing;
        break;
    case 2: // medium
        makeRandomBoard(20);
        state = State::playing;
        break;
    case 3: // hard
        makeRandomBoard(10);
        state = State::playing;
        break;
    case 4: // custom
        customGridMenu();
        state = State::playing;
        break;
    case 5: // back
        state = State::mainMenu;
        break;
    default:
        std::cout << "Invalid input\n";
        break;
    }
}

void Sudoku::customGridMenu() {
    int num = -1;
    while(num < 0 && num >= ROWS * COLS) {
        std::cout << "Enter how many numbers you want set on your board\n";
        std::cin >> num;
    }
    makeRandomBoard(num);
}

void Sudoku::playBoard() {
    printGrid();
    std::cout << "Enter the coordinates then the number to place at the coordinates.\nE.G. 0, 2, 2 would place a 2 at row 0 column 2\nOr enter 0 0 0 to exit the game\n";
    int r = -1, c = -1, num = -1;
    std::cin >> r >> c >> num;
    bool validInput = validCoordinate(r) && validCoordinate(c) && validNumber(num);
    if(validInput) {
        processValidBoardInput(r, c, num);
    } else if(r == c == num == 0) {
        std::cout << "Exiting game\n";
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

int Sudoku::getNumber(const int & r, const int & c) const {
    return grid[r][c];
}

void Sudoku::makeRandomBoard(const int& numRandomInputs) {
    for(int i = 0; i < numRandomInputs; i++) {
        // TODO
    }
}

void Sudoku::processValidBoardInput(const int& r, const int& c, const int& num) {
    std::cout << "Setting row " << r << " and column " << c << " to " << num << '\n';
    setNumber(r, c, num);
    solver->isInvalidNumLocation(grid, r, c, num);
}

void Sudoku::printGrid() const {
    std::cout << "    0 1 2  3 4 5  6 7 8\n";
    for(int row = 0; row < ROWS; row++) {
        if(row % 3 == 0) printHorizontal();
        std::cout << row << ' ';
        for(int col = 0; col < COLS; col++) {
            if(col % 3 == 0) std::cout << '|';
            (grid[row][col]) ? std::cout << grid[row][col] : std::cout << " ";
            std::cout << ' ';
        }
        std::cout << "|\n";
    }
    printHorizontal();
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
    return solver->isBoardSolved(grid);
}

bool Sudoku::validNumber(const int& num) const {
    if(num > 0 && num <= 9)
        return true;
    return false;
}

bool Sudoku::validCoordinate(const int& coord) const {
    if(coord >= 0 && coord < 9)
        return true;
    return false;
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
    std::cout << "New Board\n1: Easy\n2: Medium\n3: Hard\n4: Custom Board\n5: Back\n";
}

void Sudoku::printHorizontal() const {
    std::cout << "  ----------------------\n";
}

void Sudoku::printGoodbye() const {
    std::cout << "Thank you for playing!\nSee you next time!\n";
}
