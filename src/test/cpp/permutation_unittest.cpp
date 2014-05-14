#include <vector>
#include <cstdarg>
#include "gtest/gtest.h"
#include "../../main/cpp/permutation.hpp"

#include <iostream>

std::vector<unsigned int> create_image(unsigned int points, ...);

TEST(PermutationTest, ImageIdentity) {
  Permutation id;

  for (unsigned int n = 0; n < 5; ++n) {
    EXPECT_EQ(n, id(n));
  }
}

TEST(PermutationTest, Image10) {
  Permutation p = Permutation(create_image(2, 1, 0));

  EXPECT_EQ(1, p(0));
  EXPECT_EQ(0, p(1));
}

TEST(PermutationTest, Multiplication) {
  Permutation p = Permutation(create_image(3, 1, 0, 2));
  Permutation q = Permutation(create_image(3, 0, 2, 1));

  Permutation product = p * q;

  EXPECT_EQ(1, product(0));
  EXPECT_EQ(2, product(1));
  EXPECT_EQ(0, product(2));
}

TEST(PermutationTest, Inverse) {
  Permutation p = Permutation(create_image(3, 1, 2, 0));

  Permutation inverse = p.inverse();

  EXPECT_EQ(2, inverse(0));
  EXPECT_EQ(0, inverse(1));
  EXPECT_EQ(1, inverse(2));
}

TEST(PermutationTest, Equality) {
  Permutation p = Permutation(create_image(3, 1, 2, 0)).inverse();
  Permutation q = Permutation(create_image(3, 2, 0, 1));

  EXPECT_EQ(p, q);
}

TEST(PermutationTest, Inequality) {
  Permutation p = Permutation(create_image(3, 1, 2, 0)).inverse();

  EXPECT_NE(p, p.inverse());
}

TEST(PermutationTest, Base) {
  static const unsigned int max_base = 100;

  Permutation id;
  for (unsigned int n = 0; n < max_base; ++n) {
    EXPECT_EQ(n, id(n));
  }

  Permutation p = Permutation(create_image(5, 1, 2, 3, 4, 0));
  for (unsigned int n = 5; n < max_base; ++n) {
    EXPECT_EQ(n, p(n));
  }
}

TEST(PermutationTest, OutputOperator) {
  std::stringstream ss;
  ss << Permutation(create_image(6, 0, 2, 3, 1, 5, 4));
  EXPECT_STREQ("(1 2 3)(4 5)", ss.str().c_str());

  ss.str("");
  ss << Permutation();
  EXPECT_STREQ("Id", ss.str().c_str());
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
