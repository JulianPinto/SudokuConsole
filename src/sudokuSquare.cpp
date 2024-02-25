
#include "sudokuSquare.h"

sudokuSquare::sudokuSquare() {}

sudokuSquare::sudokuSquare(const int& val) : value{val} {}

sudokuSquare::~sudokuSquare() {}

void sudokuSquare::resetSquare() {
    value = 0;
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

int sudokuSquare::getValue() const {
    return value;
}

void sudokuSquare::setValue(const int& val) {
    value = val;
}

sudokuSquare& sudokuSquare::operator= (const int& val) {
    value = val;
    return *this;
}

sudokuSquare::operator int() const {
    return value;
}
