//
// Created by Nydus0 on 25/07/2025.
//

#include "solutions/arrays_hashing.hpp"

#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

template <typename T, typename BinaryPredicate>
bool compare_all_pairs(const std::vector<T>& vec, BinaryPredicate comp) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (!comp(vec[i], vec[j])) {
                return false;
            }
        }
    }
    return true;
}


TEST(arrays_hashing, contains_duplicate) {
    vector nums1 {1, 2, 3, 1};
    vector nums2 {1, 2, 3, 4};
    vector nums3 {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    EXPECT_EQ(containsDuplicate(nums1), true);
    EXPECT_EQ(containsDuplicate(nums2), false);
    EXPECT_EQ(containsDuplicate(nums3), true);
}

TEST(arrays_hashing, is_anagram) {
    EXPECT_EQ( isAnagram("anagram", "nagaram"), true);
    EXPECT_EQ( isAnagram("cat", "car"), false);
}


TEST(arrays_hashing, two_sum) {
    vector nums1 {2, 7, 11, 15};
    vector nums2 {3, 2, 4};

    EXPECT_EQ(twoSumArrays(nums1, 9), vector({0, 1}));
    EXPECT_EQ(twoSumArrays(nums2, 6), vector({1, 2}));
}


TEST(arrays_hashing, group_anagrams) {

    vector<string> vec1 {"act","pots","tops","cat","stop","hat"};
    vector<string> vec2 {"x"};
    vector<string> vec3;

    const auto result1 = groupAnagrams(vec1);
    for (auto& list : result1) {
        if (list.size() > 1) {
            auto comparison_result = compare_all_pairs(list, [&](const string& a, const string& b) {
                return ranges::is_permutation(a, b); });
            EXPECT_EQ(comparison_result, true);
        }
    }

    const auto result2 = groupAnagrams(vec2);
    EXPECT_EQ(result2.size(), 1); EXPECT_EQ(result2[0][0], "x");

    EXPECT_EQ(groupAnagrams(vec3).empty(), true);
}

TEST(arrays_hashing, top_k_frequent) {
    vector vec1 {1,2,2,3,3,3};
    vector vec2 {-1, -1};

    EXPECT_TRUE(ranges::is_permutation(topKFrequent(vec1,2), vector({2,3})));
    EXPECT_EQ(topKFrequent(vec2,1), vector({-1}));
}


TEST(arrays_hashing, product_except_self) {
    vector nums1 {1, 2, 4, 6};
    EXPECT_EQ(productExceptSelf(nums1), vector({48, 24, 12, 8}));
    vector nums2 {-1, 0, 1, 2, 3};
    EXPECT_EQ(productExceptSelf(nums2), vector({0, -6, 0, 0, 0}));
}


TEST(arrays_hashing, valid_sudoku) {
    vector<vector<char>> board1 {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    EXPECT_EQ(isValidSudoku(board1), true);

    vector<vector<char> > board2{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '9', '1', '.', '.', '.', '.', '.', '3'},
        {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
        {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    EXPECT_EQ(isValidSudoku(board2), false);

}

TEST(arrays_hashing, longest_consecutive) {
    vector nums1 {2, 20, 4, 10, 3, 4, 5};
    EXPECT_EQ(longestConsecutive(nums1), 4);
    vector nums2 {0, 3, 2, 5, 4, 6, 1, 1};
    EXPECT_EQ(longestConsecutive(nums2), 7);
}
