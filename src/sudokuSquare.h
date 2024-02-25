#pragma once
class sudokuSquare
{
public:
    sudokuSquare();
    sudokuSquare(const int& val);
    ~sudokuSquare();
    void resetSquare();
    void makeFixed();
    void unFixSquare();
    bool isFixed() const;
    int getValue() const;
    void setValue(const int& val);

    sudokuSquare& operator=(const int& val);
    operator int() const;

private:
    int value{0};
    bool fixed{false};
};
