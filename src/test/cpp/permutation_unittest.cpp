#include <vector>
#include "gtest/gtest.h"
#include "../../main/cpp/permutation.hpp"

TEST(PermutationTest, ImageIdentity) {
  static const int max_base = 100;

  Permutation id;

  for (int n = 0; n < max_base; ++n) {
    EXPECT_EQ(n, id(n));
  }
}

TEST(PermutationTest, Image10) {
  static const int max_base = 100;

  std::vector<int> image;
  image.push_back(1);
  image.push_back(0);
  Permutation p = Permutation(image);

  EXPECT_EQ(1, p(0));
  EXPECT_EQ(0, p(1));


  for (int n = 2; n < max_base; ++n) {
    EXPECT_EQ(n, p(n));
  }
}
