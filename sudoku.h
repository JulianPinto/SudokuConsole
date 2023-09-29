#pragma once
#include <vector>
#include "SudokuSolver.h"
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

    State state{State::mainMenu};
    sudokuBoard board;
    SudokuSolver* solver;
    bool errorCheck{false};

public:
    Sudoku(SudokuSolver* solver);
    ~Sudoku();
    void run();

private:
    void mainMenu();
    void newBoard();
    void playBoard();
    void settings();

    void resetGrid();
    void makeRandomBoard(const int& numRandomInputs);
    void customGridMenu();
    void processValidBoardInput(const int& r, const int& c, const int& num);
    void setNumber(const int& r, const int& c, const int& num);
    int getNumber(const int& r, const int& c) const;
    bool validNumber(const int& num) const;
    bool validCoordinate(const int& coord) const;
    int getRandomNumber() const;

    void checkBoardComplete();
    bool isBoardValid() const;
    bool isBoardSolved() const;

    void printGrid() const;
    void printMenu() const;
    void printSettings() const;
    void printNewBoardMenu() const;
    void printHorizontal() const;
    void printGoodbye() const;
};
