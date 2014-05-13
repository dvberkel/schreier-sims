#include <vector>
#include <cstdarg>
#include "gtest/gtest.h"
#include "../../main/cpp/permutation.hpp"

#include <iostream>

std::vector<unsigned int> create_image(unsigned int points, ...);

static const unsigned int max_base = 100;

TEST(PermutationTest, ImageIdentity) {
  Permutation id;

  for (unsigned int n = 0; n < max_base; ++n) {
    EXPECT_EQ(n, id(n));
  }
}

TEST(PermutationTest, Image10) {
  Permutation p = Permutation(create_image(2, 1, 0));

  EXPECT_EQ(1, p(0));
  EXPECT_EQ(0, p(1));


  for (unsigned int n = 2; n < max_base; ++n) {
    EXPECT_EQ(n, p(n));
  }
}

std::vector<unsigned int> create_image(unsigned int points, ...) {
  std::vector<unsigned int> image;
  va_list arguments;
  va_start(arguments, points);
  while (points--) {
    unsigned int value = va_arg(arguments, unsigned int);
    image.push_back(value);
  }
  va_end(arguments);
  return image;
}
