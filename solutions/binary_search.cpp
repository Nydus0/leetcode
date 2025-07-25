#include "solutions/binary_search.hpp"

#include <algorithm>
#include <cmath>

using namespace std;

int search(vector<int>& nums, int target) {
    // find iterator
    auto iterator = lower_bound(nums.begin(), nums.end(), target);
    // if found, get index
    if (iterator != nums.end()) {
        int index = iterator - nums.begin();
        if (nums[index] == target) {
            return index;
        }
    }
    return -1;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix[0].size();
    int m = matrix.size();

    // create vector of row representatives (first element of row)
    vector<int> top_level(m);
    for (int i = 0; i < m; i++) {
        top_level[i] = matrix[i][0];
    }

    // binary search at top level (for rows)
    auto row_it = upper_bound(top_level.begin(), top_level.end(), target);
    // get index of row (caution : upper_bound retrieves first element > target so right row index is found row index - 1)
    int row_index = row_it - top_level.begin() - 1;
    if (row_index < 0) {
        return false;
    }

    // binary search in the selected row
    return binary_search(matrix[row_index].begin(), matrix[row_index].end(), target);
}

int minEatingSpeed(vector<int>& piles, int h) {
    auto high_speed = *max_element(piles.begin(), piles.end());
    int low_speed = 1;

    // binary search
    while (low_speed <= high_speed) {
        // set mid speed for bs
        auto k = (low_speed + high_speed) / 2;

        // init number of hours spent for every pile
        long int hours = 0;  // long int to avoid overflows

        // count total hours spent with k speed
        for (auto elt : piles) {
            hours += 1 + ((elt - 1) / k);  // fast ceiling of an integer division
        }

        // update range of binary search
        if (hours <= h) {
            high_speed = k - 1;
        } else {
            low_speed = k + 1;
        }
    }

    // in case there are several solutions, return the minimum solution
    return low_speed;
}

int findMin(std::vector<int>& nums) {
    int size = nums.size() - 1;
    // init binary search range
    int upper_bound = size;
    int lower_bound = 0;
    // init index at middle of input vector
    int index = size / 2;

    // binary search for search of minimum
    while (index != lower_bound && index != upper_bound) {
        // update range of binary search
        if (nums[index] < nums[upper_bound]) {
            upper_bound = index;
        } else {
            lower_bound = index;
        }
        // reset index at middle of updated range
        index = (lower_bound + upper_bound) / 2;
    }

    // select minimum
    if (nums[upper_bound] < nums[lower_bound]) {
        return nums[upper_bound];
    } else {
        return nums[lower_bound];
    }
}

int search_in_rotated_array(vector<int>& nums, int target) {
    int size = nums.size() - 1;
    // init binary search range
    int upper_bound = size;
    int lower_bound = 0;
    // init index at middle of input vector
    int index = size / 2;

    // binary search for search of index of minimum
    while (index != lower_bound && index != upper_bound) {
        // update range of binary search
        if (nums[index] < nums[upper_bound]) {
            upper_bound = index;
        } else {
            lower_bound = index;
        }
        // reset index at middle of updated range
        index = (lower_bound + upper_bound) / 2;
    }

    // select index of minimum
    if (nums[upper_bound] < nums[lower_bound]) {
        index = upper_bound;
    } else {
        index = lower_bound;
    }

    // rotate to get sorted ascending data
    rotate(nums.begin(), nums.begin() + index, nums.end());

    // binary search for target
    auto target_it = equal_range(nums.begin(), nums.end(), target);

    int result = distance(nums.begin(), target_it.first) + index;

    // cases when target does not exist in nums
    if (target_it.first == nums.end()              // no elements not less than target
        || (target_it.first == target_it.second))  // first element greater than value equals last element not less than target
    {
        result = -1;
    }

    // correct std::distance formula in case of vector of 2 elements
    if (result > size) {
        result -= (size + 1);
    }

    return result;
}