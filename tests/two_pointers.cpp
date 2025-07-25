//
// Created by Nydus0 on 25/07/2025.
//

#include "solutions/two_pointers.hpp"

#include <gtest/gtest.h>

using namespace std;

TEST(two_pointers, is_palindrome) {
    const string s1 {"Was it a car or a cat I saw?"};
    const string s2 {"tab a cat"};

    EXPECT_EQ(isPalindrome(s1), true);
    EXPECT_EQ(isPalindrome(s2), false);
}

TEST(two_pointers, two_sum) {
    vector nums1 {1, 2, 3, 4};
    EXPECT_EQ(twoSumPointers(nums1, 3), vector({1, 2}));
}
