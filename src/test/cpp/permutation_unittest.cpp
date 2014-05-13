#include "../../main/cpp/permutation.hpp"
#include "gtest/gtest.h"

TEST(PermutationTest, Identity) {
  static const int max_base = 100;

  Permutation id;

  for (int n; n < max_base; ++n) {
    EXPECT_EQ(n, id(n));
  }
}
