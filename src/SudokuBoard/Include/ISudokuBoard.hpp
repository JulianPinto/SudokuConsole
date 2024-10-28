#pragma once

#include "SudokuSquare.hpp"

class ISudokuBoard
{
public:
    virtual ~ISudokuBoard() = 0;
    //Board operations
    virtual void ClearAllBoard() = 0;
    virtual void ResetUnlockedSquares() = 0;
    virtual void FixAllValues() = 0;
    //Square operations
    virtual size_t GetSquareValue(const size_t& r, const size_t& c) = 0;
    virtual bool SetSquareValue(const size_t& r, const size_t& c, const size_t& val) = 0;
    virtual void LockSquare(const size_t& r, const size_t& c) = 0;
    virtual void UnlockSquare(const size_t& r, const size_t& c) = 0;
    virtual bool ClearSquare(const size_t& r, const size_t& c) = 0;
};