
#include "SudokuSquare.hpp"

SudokuSquare::SudokuSquare() {}

SudokuSquare::SudokuSquare(const size_t& val) : value{val} {}

SudokuSquare::~SudokuSquare() {}

void SudokuSquare::resetSquare() {
    value = 0;
    fixed = false;
}

void SudokuSquare::makeFixed() {
    fixed = true;
}

void SudokuSquare::unFixSquare() {
    fixed = false;
}

bool SudokuSquare::isFixed() const {
    return fixed;
}

size_t SudokuSquare::getValue() const {
    return value;
}

void SudokuSquare::setValue(const size_t& val) {
    value = val;
}

SudokuSquare& SudokuSquare::operator= (const size_t& val) {
    value = val;
    return *this;
}

SudokuSquare::operator size_t() const {
    return value;
}
