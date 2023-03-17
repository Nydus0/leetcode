#pragma once

#include "Solution.hpp"

class SolTwoPointers : public Solution {
   public:
    bool isPalindrome(std::string s);
    std::vector<int> twoSum(std::vector<int>& numbers, int target);
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
    int maxArea(std::vector<int>& height);
};
