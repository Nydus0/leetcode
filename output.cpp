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

