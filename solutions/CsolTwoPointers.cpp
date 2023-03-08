#include "CsolTwoPointers.h"

#include <algorithm>
#include <iostream>
#include <set>

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

vector<vector<int>> CsolTwoPointers::threeSum(vector<int>& nums) {
    vector<vector<int>> result; //output result
    set<vector<int>> solutions; //set container only contains unique values
    sort(nums.begin(), nums.end());

    if (nums.size() == 0) {
        return result;
    }

    for (int i = 0; i < nums.size() - 1; i++) {
        int target = -nums[i]; //fix i
        int low = i+1; //instantiate low pointer
        int high = nums.size()-1; //instantiate high pointer

        while (low < high) {
            int sum = nums[low] + nums[high];
            // sum must not contain fixed index i
            if (sum == target) {
                solutions.insert({nums[low], nums[high], nums[i]});
                // next possible valid target cannot contain either actual low or high
                // so continue iterating for both indexes
                    low++;
                    high--;
            } else if (sum < target) {
                low++;
            } else  // sum > target
            {
                high--;
            }
        }
    }

    //fill result
    for (auto vec : solutions) {
        result.push_back(vec);
    }

    return result;
}