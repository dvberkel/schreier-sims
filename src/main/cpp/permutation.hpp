#pragma once

#include <vector>

class Permutation {
public:
  Permutation();
  Permutation(std::vector<unsigned int>);
  unsigned int operator()(unsigned int) const;
  Permutation operator*(const Permutation) const;
  Permutation inverse() const;
  bool operator==(const Permutation) const;
private:
  std::vector<unsigned int> image;
};
