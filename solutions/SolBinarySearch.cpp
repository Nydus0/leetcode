#include "SolBinarySearch.hpp"

#include <algorithm>
#include <cmath>

using namespace std;

int SolBinarySearch::search(vector<int>& nums, int target) {
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

bool SolBinarySearch::searchMatrix(vector<vector<int>>& matrix, int target) {
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

int SolBinarySearch::minEatingSpeed(vector<int>& piles, int h) {
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

        // update scope of binary search
        if (hours <= h) {
            high_speed = k - 1;
        } else {
            low_speed = k + 1;
        }
    }

    // in case there are several solutions, return the minimum solution
    return low_speed;
}