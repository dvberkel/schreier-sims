#pragma once

#include <vector>
#include <iostream>

class Permutation {
public:
  Permutation();
  Permutation(std::vector<unsigned int>);
  unsigned int base() const;
  unsigned int operator()(unsigned int) const;
  Permutation operator*(const Permutation&) const;
  Permutation inverse() const;
  bool operator==(const Permutation&) const;
  bool operator!=(const Permutation&) const;
private:
  std::vector<unsigned int> image;
};

std::ostream& operator<<(std::ostream&, const Permutation&);
