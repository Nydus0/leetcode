#include "output.hpp"

#include <iostream>
#include <vector>

#include "solutions/sol_binary_search.hpp"
#include "solutions/sol_two_pointers.hpp"

using namespace std;

void output::is_palindrome() {
    cout << "--- is palindrome \n";
    sol_two_pointers sol;
    string input{"0P"};
    bool result = sol.isPalindrome(input);
    cout << "result = " << result << "\n";
}

void output::two_sum_sorted() {
    cout << "--- two sum sorted \n";
    sol_two_pointers sol;
    vector input{2, 7, 11, 15};
    vector<int> result = sol.twoSum(input, 9);
    cout << "result = " << result[0] << " " << result[1] << "\n";
}

void output::three_sum() {
    cout << "--- three sum \n";
    sol_two_pointers sol;
    vector input{-1, 0, 1, 2, -1, -4};
    vector input2{1, 2, -2, -1};
    vector<int> input3;

    vector<vector<int>> result = sol.threeSum(input);

    cout << "result\n";
    for (auto elt : result) {
        cout << "[" << elt[0] << " " << elt[1] << " " << elt[2] << "]\n";
    }
}

void output::max_area() {
    cout << "--- max area \n";

    sol_two_pointers sol;
    vector<int> vec{1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = sol.maxArea(vec);

    cout << "result = " << result << "\n";
}

void output::search() {
    cout << "--- binary search \n";

    sol_binary_search sol;
    vector<int> vec{-1, 0, 3, 5, 9, 12};
    int target = 2;
    int result = sol.search(vec, target);

    cout << "result = " << result << "\n";
}

void output::search_matrix() {
    cout << "--- matrix binary search \n";

    sol_binary_search sol;
    vector<vector<int>> vec{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    int result = sol.searchMatrix(vec, target);
    cout << "result = " << result << "\n";
}

void output::min_eating_speed() {
    cout << "--- min eating speed \n";

    sol_binary_search sol;
    vector<int> piles{1,1,1,999999999};
    vector<int> piles_2{312884470};
    int target = 10;
    int target_2 = 312884469;
    int result = sol.minEatingSpeed(piles, target);
    cout << "result = " << result << "\n";
}

void output::find_min() {
     cout << "--- find min in rotated sorted array \n";

     sol_binary_search sol;
     vector<int> nums{11,13,15,17};
     int result = sol.findMin(nums);
     cout << "result = " << result << "\n";
}

void output::search_in_rotated_array() {
    cout << "--- search in rotated sorted array \n";

    sol_binary_search sol;
    vector<int> nums{4,5,6,7,0,1,2};
    vector<int> nums2{3,1};
    int target = 3;
    int result = sol.search_in_rotated_array(nums2, target);
    cout << "result = " << result << "\n";
}

void output::time_map() {
    cout << "--- time map \n";
    cout << "no output implementation yet \n";
}

void output::invert_tree() {
    cout << "--- invert tree \n";
    cout << "no output implementation yet \n";
}

void output::max_depth() {
    cout << "--- max depth \n";
    cout << "no output implementation yet \n";
}

void output::diameter() {
    cout << "--- diameter \n";
    cout << "no output implementation yet \n";
}

