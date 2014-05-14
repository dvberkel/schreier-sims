#include "permutation.hpp"

#include <algorithm>

Permutation::Permutation() : image(std::vector<unsigned int>()) {}
Permutation::Permutation(std::vector<unsigned int> image) : image(image) {}

unsigned int Permutation::base() const {
  return image.size();
}

unsigned int Permutation::operator()(unsigned int n) const {
  if (n < base()) {
    return image[n];
  }
  return n;
}

Permutation Permutation::operator*(const Permutation& q) const {
  unsigned int max_base = std::max(this->base(), q.base());
  std::vector<unsigned int> image;
  for (unsigned int point = 0; point < max_base; ++point) {
    image.push_back((*this)(q(point)));
  }
  return Permutation(image);
}

Permutation Permutation::inverse() const {
  std::vector<unsigned int> image(this->base());
  for (unsigned int point = 0; point < this->base(); ++point) {
    image[(*this)(point)] = point;
  }
  return Permutation(image);
}

bool Permutation::operator==(const Permutation& q) const {
  unsigned int max_base = std::max(this->base(), q.base());
  for (unsigned int point = 0; point < max_base; ++point) {
    if ((*this)(point) != q(point)) {
      return false;
    }
  }
  return true;
}

bool Permutation::operator!=(const Permutation& q) const {
  return !((*this) == q);
}

void cycleOf(const Permutation& p, const unsigned int start, std::vector<unsigned int>& visited, std::vector<unsigned int>& cycle) {
  visited.push_back(start);
  cycle.push_back(start);
  unsigned int next = p(start);
  while (next != start) {
    visited.push_back(next);
    cycle.push_back(next);
    next = p(next);
  }
}

bool contains(const std::vector<unsigned int> haystack, unsigned int needle) {
  return std::find(haystack.begin(), haystack.end(), needle) == haystack.end();
}

void cyclesOf(const Permutation& p, std::vector<std::vector<unsigned int> >& cycles) {
  std::vector<unsigned int> visited;
  for (unsigned int point = 0; point < p.base(); ++point) {
    if (contains(visited, point)) {
      std::vector<unsigned int> cycle;
      cycleOf(p, point, visited, cycle);
      if (cycle.size() != 1) {
	cycles.push_back(cycle);
      }
    }
  }
}

void outputCycle(std::ostream& os, std::vector<unsigned int>& cycle) {
  os << "(";
  for (unsigned int index = 0; index < (cycle.size() - 1); ++index) {
    os << cycle[index] << " ";
  }
  os << cycle[cycle.size() - 1];
  os << ")";
}

void outputCycles(std::ostream& os, std::vector<std::vector<unsigned int> >& cycles) {
  if (cycles.size() > 0) {
    for (
	 std::vector<std::vector<unsigned int> >::iterator cycle_ptr = cycles.begin();
	 cycle_ptr != cycles.end();
	 ++cycle_ptr
    ) {
      outputCycle(os, *cycle_ptr);
    }
  } else {
    os << "Id";
  }
}

std::ostream& operator<<(std::ostream& os, const Permutation& p) {
  std::vector<std::vector<unsigned int> > cycles;
  cyclesOf(p, cycles);
  outputCycles(os, cycles);
  return os;
}
