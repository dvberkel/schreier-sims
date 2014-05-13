#include "permutation.hpp"

Permutation::Permutation() : image(std::vector<unsigned int>()) {}
Permutation::Permutation(std::vector<unsigned int> image) : image(image) {}

int Permutation::operator()(unsigned int n) {
  if (n < image.size()) {
    return image[n];
  }
  return n;
}
