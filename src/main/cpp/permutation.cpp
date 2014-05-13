#include "permutation.hpp"

Permutation::Permutation() : image(std::vector<unsigned int>()) {}
Permutation::Permutation(std::vector<unsigned int> image) : image(image) {}

int Permutation::operator()(unsigned int n) {
  if (n < image.size()) {
    return image[n];
  }
  return n;
}

Permutation Permutation::operator*(Permutation q) {
  unsigned int max_base = std::max(this->image.size(), q.image.size());
  std::vector<unsigned int> image;
  for (unsigned int point = 0; point < max_base; point++) {
    image.push_back((*this)(q(point)));
  }
  return Permutation(image);
}
