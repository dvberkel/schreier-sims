#pragma once

#include <vector>

class Permutation {
public:
  Permutation();
  Permutation(std::vector<unsigned int>);
  int operator()(unsigned int);
  Permutation operator*(Permutation);
private:
  std::vector<unsigned int> image;
};
