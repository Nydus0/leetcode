#include "CsolTwoPointers.h"

#include <algorithm>
#include <iostream>

using namespace std;

bool CsolTwoPointers::isPalindrome(string s) {
    string raw_str{""};

    for (auto symbol : s) {
        // test ascii symbols
        if ((symbol >= 48 && symbol <= 57) || (symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122)) {
            raw_str += symbol;
        }
    }

    transform(raw_str.begin(), raw_str.end(), raw_str.begin(), [](unsigned char c) { return std::tolower(c); });

    int left_index = 0;
    int right_index = raw_str.size() - 1;

    if (right_index < 0) {
        return true;
    }

    while (left_index <= right_index) {
        if (raw_str[left_index] != raw_str[right_index]) {
            return false;
        }
        left_index++;
        right_index--;
    }

    return true;
}

vector<int> CsolTwoPointers::twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    
    // no sorting to do - numbers is already sort

    int l_index = 0;
    int r_index = numbers.size() - 1;

    while (l_index < r_index) {

        int sum = numbers[l_index] + numbers[r_index];

        if (sum == target) {
            result.push_back(l_index + 1);
            result.push_back(r_index + 1);
            return result;
        } else if (sum < target) {
            l_index++;
        } else  // sum > target
        {
            r_index--;
        }
    }
    return {};
}