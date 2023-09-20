#pragma once
#include <vector>
#include "SudokuSolver.h"

class Sudoku
{
private:
    enum class State: int {
        mainMenu,
        newBoard,
        playing,
        creatingBoard,
        exit
    };

    const int ROWS{9};
    const int COLS{9};
    State state{State::mainMenu};
    std::vector<std::vector<int>> grid;

public:
    Sudoku();
    ~Sudoku();
    void run();

private:
    void mainMenu();
    void newBoard();
    void playBoard();

    void resetGrid();
    void makeRandomBoard(const int& numRandomInputs);
    void addRandomNumberToGrid();
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
    void customGridMenu();
    void printNewBoardMenu() const;
    void printHorizontal() const;
    void printGoodbye() const;
};
