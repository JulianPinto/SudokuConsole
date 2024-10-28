
#include "SudokuSquare.hpp"

SudokuSquare::SudokuSquare() {}

SudokuSquare::SudokuSquare(const size_t& val) : value{val} {}

SudokuSquare::~SudokuSquare() {}

void SudokuSquare::ResetSquare() {
    value = 0;
    locked = false;
}

void SudokuSquare::LockSquare() {
    locked = true;
}

void SudokuSquare::UnlockSquare() {
    locked = false;
}

bool SudokuSquare::IsLocked() const {
    return locked;
}

size_t SudokuSquare::GetValue() const {
    return value;
}

bool SudokuSquare::SetValue(const size_t& val) {
    if(locked)
        return false;
    value = val;
    return true;
}