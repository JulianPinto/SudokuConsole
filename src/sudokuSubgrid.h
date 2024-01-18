#pragma once

#include <vector>
#include "Constants.h"
#include "sudokuSquare.h"

class sudokuSubgrid {
public:
  sudokuSubgrid(const sudokuBoard* subGrid, const int& r, const int& c);
  ~sudokuSubgrid();

  void fillSubgrid();
  int& operator[](const int& id);
  
private:
  std::vector<int> makeRandomIndexes(const int &numIndex);

  int row, col;
  sudokuBoard* subGridPtr;
};
