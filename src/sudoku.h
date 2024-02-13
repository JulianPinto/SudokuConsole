#pragma once
#include <vector>
#include "SudokuSolver.h"
#include "sudokuBoardMaker.h"
#include "Constants.h"

class Sudoku
{
private:
    enum class State: int {
        mainMenu,
        newBoard,
        playing,
        creatingBoard,
        settings,
        exit
    };

    const char* RESET_COLOR = "\033[0m";
    const char* CORRECT_COLOR = "\033[1;32m";
    const char* INCORRECT_COLOR = "\033[1;31m";

    State state{State::mainMenu};
    sudokuBoard board;
    SudokuSolver* solver;
    sudokuBoardMaker boardMaker;
    bool errorCheck{false};

public:
    Sudoku(SudokuSolver* solver);
    ~Sudoku();
    void run();

private:
    // menu functions
    void mainMenu();
    void newBoard();
    void playBoard();
    void settings();

    // board functions
    void resetGrid();
    void makeSudokuBoard();
    void displayStarterNumbers(const SudokuDifficulty& dif);
    void hideNumbers(const int& dif);
    void processValidBoardInput(const int& r, const int& c, const int& num);
    void setNumber(const int& r, const int& c, const int& num);
    bool validNumber(const int& num) const;
    bool validCoordinates(const int& row, const int& col) const;
    bool inputValid(const int& r, const int& c, const int& num);
    int getRandomNumber() const;

    void checkBoardComplete();
    bool isBoardValid() const;
    bool isBoardSolved() const;

    // print functions
    void printGrid() const;
    void printNumber(const int& col, const int& row) const;
    void printMenu() const;
    void printSettings() const;
    void printNewBoardMenu() const;
    void printHorizontal() const;
    void printGoodbye() const;
};
