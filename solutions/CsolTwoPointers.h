#pragma once

#include "solution.h"

class CsolTwoPointers : public solution {
   public:
    bool isPalindrome(std::string s);
    std::vector<int> twoSum(std::vector<int>& numbers, int target);
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
};

