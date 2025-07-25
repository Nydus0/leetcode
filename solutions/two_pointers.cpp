#include "solutions/two_pointers.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>

using namespace std;

bool isPalindrome(string s) {
    string raw_str;

    for (const auto symbol : s) {
        // test ascii symbols
        if ((symbol >= 48 && symbol <= 57) || (symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122)) {
            raw_str += symbol;
        }
    }

    ranges::transform(raw_str, raw_str.begin(), [](const unsigned char c) { return std::tolower(c); });

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

vector<int> twoSumPointers(vector<int>& numbers, int target) {
    vector<int> result;

    // no sorting to do - numbers is already sorted

    int l_index = 0;
    int r_index = numbers.size() - 1;

    while (l_index < r_index) {
        const int sum = numbers[l_index] + numbers[r_index];

        if (sum == target) {
            result.push_back(l_index + 1);
            result.push_back(r_index + 1);
            return result;
        }
        if (sum < target) {
            l_index++;
        } else  // sum > target
        {
            r_index--;
        }
    }
    return result;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;  // output result
    set<vector<int>> solutions;  // set container only contains unique values
    ranges::sort(nums);

    if (nums.empty()) {
        return result;
    }

    for (int i = 0; i < nums.size() - 1; i++) {
        const int target = -nums[i];       // fix i
        int low = i + 1;             // instantiate low pointer
        int high = nums.size() - 1;  // instantiate high pointer

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

    // fill result
    for (const auto& vec : solutions) {
        result.push_back(vec);
    }

    return result;
}

int maxArea(vector<int>& height) {
    int max_area = 0;
    const int size = height.size();
    int left = 0;
    int right = size - 1;

    // brute force complexity is O(n^2)
    // optimal solution with 2 pointers complexity is O(n)
    // to avoid 2 for loops, set 2 pointers at max distance and test all areas between them
    // and move lower height pointer towards the other pointers at each iteration
    // this method ensures all areas are tested and avoids computing some useless areas

    while (left < right) {
        // compute area
        const int dist = right - left;
        const int min_height = min(height[left], height[right]);
        int area = dist * min_height;
        // determine max area
        if (area > max_area) {
            max_area = area;
        }
        // finally iterate through pointers
        if (height[left] < height[right]) {
            left++;
        } else if (height[left] > height[right]) {
            right--;
        } else {
            left++;
            right--;
        }
    }

    return max_area;
}