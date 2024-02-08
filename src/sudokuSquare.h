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
    int getDisplay();
    void setDisplay(const int& val);
    int& getValue();
    bool isCorrect();

    sudokuSquare& operator=(const int& val);
    operator int() const;

private:
    int value{0};
    int display{0};
    bool fixed{false};
};
