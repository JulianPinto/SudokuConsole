#pragma once
class SudokuSquare
{
public:
    SudokuSquare();
    SudokuSquare(const size_t& val);
    ~SudokuSquare();
    void ResetSquare();
    void LockSquare();
    void UnlockSquare();
    bool IsLocked() const;
    size_t GetValue() const;
    bool SetValue(const size_t& val);

private:
    size_t value{0};
    bool locked{false};
};
