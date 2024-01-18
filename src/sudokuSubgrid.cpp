#include "sudokuSubgrid.h"
#include <iostream>
#include <numeric>
#include <random>

sudokuSubgrid::sudokuSubgrid(const sudokuBoard* subGrid, const int& r, const int& c) : subGridPtr{subGrid}, row{r}, col{c} {}

sudokuSubgrid::~sudokuSubgrid() {}

void sudokuSubgrid::fillSubgrid() {
  std::vector<int> filler = makeRandomIndexes(9);
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      *subGridPtr[row + i][col +j] = filler.end();
      filler.pop_back();
    }
  }
}

int& sudokuSubgrid::operator[](const int& id) {
  if(id > 8 || id < 0) {
    std::err << "In sudokuSubgrid, operator[] id out of range, " << id << std::endl;
    return 0;
  }
  int r = id / ROWS;
  int c = id % ROWS;
  return *subGridPtr[row + r][col + c];
}

std::vector<int> sudokuSubgrid::makeRandomIndexes(const int &numIndex)
{
    std::vector<int> indexes(numIndex);
    std::iota(std::begin(indexes), std::end(indexes), 0);
    std::shuffle(std::begin(indexes), std::end(indexes), std::default_random_engine());
    return indexes;
}
