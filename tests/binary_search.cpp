//
// Created by Nydus0 on 25/07/2025.
//

#include "solutions/binary_search.hpp"

#include <gtest/gtest.h>

using namespace std;

TEST(binary_search, search) {
    vector nums1 {-1, 0, 2, 4, 6, 8};
    vector nums2 {-1 ,0 ,2 ,4 ,6 ,8};

    EXPECT_EQ(binSearch(nums1, 4), 3);
    EXPECT_EQ(binSearch(nums1, 3), -1);
}

TEST(binary_search, search_matrix) {
    vector<vector<int>> matrix1 {{1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};

    EXPECT_EQ(searchMatrix(matrix1, 10), true);
    EXPECT_EQ(searchMatrix(matrix1, 15), false);
}

TEST(binary_search, min_eating_speed) {
    vector piles1 {1, 4, 3, 2};
    vector piles2 {25, 10, 23, 4};

    EXPECT_EQ(minEatingSpeed(piles1, 9), 2);
    EXPECT_EQ(minEatingSpeed(piles2, 4), 25);
}

TEST(binary_search, find_min) {
    vector nums1 {3, 4, 5, 6, 1, 2};
    vector nums2 {4, 5, 0, 1, 2, 3};
    vector nums3 {4, 5, 6, 7};

    EXPECT_EQ(findMin(nums1), 1);
    EXPECT_EQ(findMin(nums2), 0);
    EXPECT_EQ(findMin(nums3), 4);
}

TEST(binary_search, search_in_rotated_array) {
    vector nums1 {3, 4, 5, 6, 1, 2};
    vector nums2 {3, 5, 6, 0, 1, 2};

    EXPECT_EQ(searchInRotatedArray(nums1, 1), 4);
    EXPECT_EQ(searchInRotatedArray(nums2, 4), -1);
}


