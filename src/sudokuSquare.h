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
    void hideValue();
    void showValue();
    int& getValue();

    sudokuSquare& operator=(const int& val);
    operator int() const;

private:
    int value{0};
    bool visible{false};
    bool fixed{false};
};
