#include "permutation.hpp"

#include <map>

Permutation::Permutation() : image(std::vector<unsigned int>()) {}
Permutation::Permutation(std::vector<unsigned int> image) : image(image) {}

unsigned int Permutation::operator()(unsigned int n) const {
  if (n < image.size()) {
    return image[n];
  }
  return n;
}

Permutation Permutation::operator*(Permutation q) {
  unsigned int max_base = std::max(this->image.size(), q.image.size());
  std::vector<unsigned int> image;
  for (unsigned int point = 0; point < max_base; ++point) {
    image.push_back((*this)(q(point)));
  }
  return Permutation(image);
}

Permutation Permutation::inverse() {
  std::vector<unsigned int> image(this->image.size());
  for (unsigned int point = 0; point < this->image.size(); ++point) {
    image[(*this)(point)] = point;
  }
  return Permutation(image);
}

bool Permutation::operator==(const Permutation q) const {
  unsigned int max_base = std::max(this->image.size(), q.image.size());
  for (unsigned int point = 0; point < max_base; ++point) {
    if ((*this)(point) != q(point)) {
      return false;
    }
  }
  return true;
}
