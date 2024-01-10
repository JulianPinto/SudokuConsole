
#include "sudokuSquare.h"

sudokuSquare::sudokuSquare() {}

sudokuSquare::sudokuSquare(const int& val) : value{val} {}

sudokuSquare::~sudokuSquare() {}

void sudokuSquare::resetSquare() {
    value = 0;
    fixed = false;
    visible = false;
}

void sudokuSquare::makeFixed() {
    fixed = true;
}

void sudokuSquare::unFixSquare() {
    fixed = false;
}

void sudokuSquare::hideValue() {
    visible = false;
}

void sudokuSquare::showValue() {
    visible = true;
}

sudokuSquare& sudokuSquare::operator= (const int& val) {
    value = val;
}

sudokuSquare::operator int() const {
    return value;
}