
#include "sudokuSquare.hpp"

sudokuSquare::sudokuSquare() {}

sudokuSquare::sudokuSquare(const size_t& val) : value{val} {}

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

size_t sudokuSquare::getValue() const {
    return value;
}

void sudokuSquare::setValue(const size_t& val) {
    value = val;
}

sudokuSquare& sudokuSquare::operator= (const size_t& val) {
    value = val;
    return *this;
}

sudokuSquare::operator size_t() const {
    return value;
}
