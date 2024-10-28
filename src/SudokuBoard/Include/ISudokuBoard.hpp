#pragma once

class ISudokuBoard
{
public:
    virtual ~ISudokuBoard() {};
    virtual size_t GetSquareValue(const size_t& r, const size_t& c) = 0;
    virtual void SetSquareValue(const size_t& r, const size_t& c, const size_t& val) = 0;
    virtual void LockSquareValue(const size_t& r, const size_t& c) = 0;
    virtual void ClearSquare(const size_t& r, const size_t& c) = 0;
};