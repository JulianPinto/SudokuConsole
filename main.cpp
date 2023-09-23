#include <iostream>
#include <stdio.h>
#include <memory>
#include "sudoku.h"
#include "SudokuSolverBruteForce.h"

int main(int argc, char *argv[]) {
    std::cout << "Welcome to Console Sudoku\n";
    SudokuSolverBruteForce *solver = new SudokuSolverBruteForce();
    Sudoku sudoku(solver);
    sudoku.run();

    return 0;
}
