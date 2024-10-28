#pragma once
class SudokuSquare
{
public:
    SudokuSquare();
    SudokuSquare(const size_t& val);
    ~SudokuSquare();
    void resetSquare();
    void makeFixed();
    void unFixSquare();
    bool isFixed() const;
    size_t getValue() const;
    void setValue(const size_t& val);

    SudokuSquare& operator=(const size_t& val);
    operator size_t() const;

private:
    size_t value{0};
    bool fixed{false};
};
