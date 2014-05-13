#pragma once

#include <vector>

class Permutation {
public:
  Permutation();
  Permutation(std::vector<int>);
  int operator()(int n);
private:
  std::vector<int> image;
};
