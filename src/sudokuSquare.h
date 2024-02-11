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
    int getDisplay() const;
    void setDisplay(const int& val);
    int& getValue();
    bool isCorrect() const;

    sudokuSquare& operator=(const int& val);
    operator int() const;

private:
    int value{0};
    int display{0};
    bool fixed{false};
};
