#include <iostream>
#include <stdio.h>
#include "Sudoku.hpp"
#include "SudokuSolverBruteForce.hpp"

int main(int argc, char *argv[]) {
    std::cout << "Welcome to Console Sudoku\n";
    SudokuSolverBruteForce solver;
    Sudoku sudoku(&solver);
    sudoku.run();

    return 0;
}
