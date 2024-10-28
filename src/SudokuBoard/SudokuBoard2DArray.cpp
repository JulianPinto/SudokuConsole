#include "SudokuBoard2DArray.hpp"
#include "Constants.hpp"

SudokuBoard2DArray::SudokuBoard2DArray() : sudokuBoard(ROWS, std::vector<SudokuSquare>(COLS))
{
}

SudokuBoard2DArray::~SudokuBoard2DArray()
{
}

void SudokuBoard2DArray::ClearAllBoard()
{
    for(int r = 0; r < ROWS; ++r)
    {
        for(int c = 0; c < COLS; ++c)
        {
            sudokuBoard.at(r).at(c).ResetSquare();
        }
    }
}

void SudokuBoard2DArray::ResetUnlockedSquares()
{
    for(int r = 0; r < ROWS; ++r)
    {
        for(int c = 0; c < COLS; ++c)
        {
            if(!sudokuBoard.at(r).at(c).IsLocked())
                sudokuBoard.at(r).at(c).ResetSquare();
        }
    }
}

void SudokuBoard2DArray::FixAllValues()
{
    for(int r = 0; r < ROWS; ++r)
    {
        for(int c = 0; c < COLS; ++c)
        {
            if(sudokuBoard.at(r).at(c).GetValue())
                sudokuBoard.at(r).at(c).LockSquare();
        }
    }
}

size_t SudokuBoard2DArray::GetSquareValue(const size_t& r, const size_t& c)
{
    return sudokuBoard.at(r).at(c).GetValue();
}

bool SudokuBoard2DArray::SetSquareValue(const size_t& r, const size_t& c, const size_t& val)
{
    return sudokuBoard.at(r).at(c).SetValue(val);
}

void SudokuBoard2DArray::LockSquare(const size_t& r, const size_t& c)
{
    sudokuBoard.at(r).at(c).LockSquare();
}

void SudokuBoard2DArray::UnlockSquare(const size_t& r, const size_t& c)
{
    sudokuBoard.at(r).at(c).UnlockSquare();
}

bool SudokuBoard2DArray::ClearSquare(const size_t& r, const size_t& c)
{
    SetSquareValue(r, c, 0);
}
