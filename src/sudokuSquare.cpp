
#include "sudokuSquare.h"

sudokuSquare::sudokuSquare() {}

sudokuSquare::sudokuSquare(const int& val) : value{val} {}

sudokuSquare::~sudokuSquare() {}

void sudokuSquare::resetSquare() {
    value = 0;
    display = 0;
    fixed = false;
}

void sudokuSquare::makeFixed() {
    fixed = true;
}

void sudokuSquare::unFixSquare() {
    fixed = false;
}

bool sudokuSquare::isFixed() const {
    return fixed;
}

int sudokuSquare::getDisplay() const {
    return display;
}

void sudokuSquare::setDisplay(const int& val) {
    display = val;
}

int& sudokuSquare::getValue() {
    return value;
}

bool sudokuSquare::isCorrect() const {
    return value == display;
}

sudokuSquare& sudokuSquare::operator= (const int& val) {
    value = val;
    return *this;
}

sudokuSquare::operator int() const {
    return value;
}
