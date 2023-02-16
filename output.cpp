#include "output.h"

#include <iostream>
#include <vector>

#include "solution.h"

using namespace std;

void output::contains_duplicate() {
    cout << "--- contains duplicate \n";

    solution sol;
    vector<int> nums1{1, 2, 3, 1};
    vector<int> nums2{1, 2, 3, 4};
    vector<int> nums3{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    cout << "result 1 = " << sol.containsDuplicate(nums1) << "\n";
    cout << "result 2 = " << sol.containsDuplicate(nums2) << "\n";
    cout << "result 3 = " << sol.containsDuplicate(nums3) << "\n";
}

void output::is_anagram() {
    cout << "--- valid anagram \n";

    solution sol;
    string s11 = "anagram";
    string s12 = "nagaram";
    string s21 = "cat";
    string s22 = "car";
    cout << "result 1 = " << sol.isAnagram(s11, s12) << "\n";
    cout << "result 2 = " << sol.isAnagram(s21, s22) << "\n";
}

void output::two_sum() {
    cout << "--- two sum \n";

    solution sol;
    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> nums2 = {3, 2, 4};
    vector<int> nums3 = {3, 3};

    vector<int> result1 = sol.twoSum(nums1, 9);
    cout << "result = " << result1[0] << " " << result1[1] << "\n";
}

void output::group_anagrams() {
    cout << "--- group anagrams \n";
    cout << "no result display \n";
}

void output::top_k_frequent() {
    cout << "--- top k frequent elements \n";

    solution sol;
    vector<int> vec_test4{1, 1, 1, 2, 2, 3};
    sol.display_vector(sol.topKFrequent(vec_test4, 2), "result");
    vector<int> vec_test5{-1, -1};
    sol.display_vector(sol.topKFrequent(vec_test5, 1), "result");
    vector<int> vec_test6{1, 2};
    sol.display_vector(sol.topKFrequent(vec_test6, 2), "result");
}

void output::product_except_self() {
    cout << "--- product except self \n";

    solution sol;
    vector<int> nums1{1, 2, 3, 4};
    sol.display_vector(sol.productExceptSelf(nums1), "result");
    vector<int> nums2{0, 0};
    sol.display_vector(sol.productExceptSelf(nums2), "result");
}

void output::valid_sudoku() {
    cout << "--- valid sudoku \n";

    solution sol;
    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    bool result1 = sol.isValidSudoku(board);
    cout << "result1 = " << result1 << "\n";

    vector<vector<char>> board2{
        {'.', '.', '.', '9', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '3', '.', '.', '.', '.', '.', '1'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'1', '.', '.', '.', '.', '.', '3', '.', '.'},
        {'.', '.', '.', '.', '2', '.', '6', '.', '.'},
        {'.', '9', '.', '.', '.', '.', '.', '7', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'8', '.', '.', '8', '.', '.', '.', '.', '.'}};

    bool result2 = sol.isValidSudoku(board2);
    cout << "result2 = " << result2 << "\n";
}

 void output::longest_consecutive() {
    cout << "--- longest consecutive \n";

    solution sol;
    vector<int> nums {100,4,200,1,3,2};
    int result = sol.longestConsecutive(nums);
    cout <<"result = " << result << "\n";

    vector<int> nums2 {0,3,7,2,5,8,4,6,0,1};
    result = sol.longestConsecutive(nums2);
    cout <<"result = " << result << "\n";
 }

