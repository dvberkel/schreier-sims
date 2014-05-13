#include "../../main/cpp/permutation.hpp"
#include "gtest/gtest.h"

TEST(PermutationTest, Identity) {
  Permutation id;

  EXPECT_EQ(1, id(1));
}
