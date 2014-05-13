#include "permutation.hpp"

Permutation::Permutation() : image(std::vector<int>()) {}
Permutation::Permutation(std::vector<int> image) : image(image) {}

int Permutation::operator()(int n) {
  if (0 <= n && n < image.size()) {
    return image[n];
  }
  return n;
}
