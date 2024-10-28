#pragma once

#include "ISudokuBoard.hpp"
#include <vector>

class SudokuBoard2DArray : public ISudokuBoard
{
public:
    SudokuBoard2DArray();
    ~SudokuBoard2DArray();

    void ClearAllBoard() override;
    void ResetUnlockedSquares() override;
    void FixAllValues() override;

    size_t GetSquareValue(const size_t& r, const size_t& c) override;
    bool SetSquareValue(const size_t& r, const size_t& c, const size_t& val) override;
    void LockSquare(const size_t& r, const size_t& c) override;
    void UnlockSquare(const size_t& r, const size_t& c) override;
    bool ClearSquare(const size_t& r, const size_t& c) override;
private:
    std::vector<std::vector<SudokuSquare>> sudokuBoard;
};
