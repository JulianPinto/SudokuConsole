#include <iostream>
#include <stdio.h>
#include "sudoku.h"
#include "SudokuSolverBruteForce.h"

int main(int argc, char *argv[]) {
    std::cout << "Welcome to Console Sudoku\n";
    SudokuSolverBruteForce solver;
    Sudoku sudoku(&solver);
    sudoku.run();

    return 0;
}
