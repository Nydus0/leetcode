#include "SolBinarySearch.hpp"

#include <algorithm>
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