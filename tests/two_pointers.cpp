//
// Created by Nydus0 on 25/07/2025.
//

#include "solutions/two_pointers.hpp"

#include <algorithm>
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


TEST(two_pointers, three_sum) {
    //example1
    vector nums1 {-1, 0, 1, 2, -1, -4};
    auto triplets1 = threeSum(nums1);

    const bool result1_1 = ranges::any_of(triplets1, [&] (const auto& triplet) {
        return ranges::is_permutation(triplet, vector({-1, -1, 2}));
    });
    const bool result1_2 = ranges::any_of(triplets1, [&] (const auto& triplet) {
            return ranges::is_permutation(triplet, vector({-1, 0, 1}));
    });
    const bool result1_3 = triplets1.size() == 2;

    EXPECT_EQ(result1_1 && result1_2 && result1_3, true);

    //example2
    vector nums2 {0, 1, 1};
    const auto triplets2 = threeSum(nums2);
    EXPECT_EQ(triplets2.empty(), true);

    //example3
    vector nums3 {0, 0, 0};
    const auto triplets3 = threeSum(nums3);
    EXPECT_EQ(triplets3, vector<vector<int>>({{0, 0, 0}}));
}

TEST(two_pointers, max_area) {
    vector height1 {1, 7, 2, 5, 4, 7, 3, 6};
    vector height2 {2, 2, 2};
    EXPECT_EQ( maxArea(height1), 36);
    EXPECT_EQ( maxArea(height2), 4);
}


