#pragma once

#include "solution.hpp"

class sol_two_pointers : public solution {
   public:
    bool isPalindrome(std::string s);
    std::vector<int> twoSum(std::vector<int>& numbers, int target);
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
    int maxArea(std::vector<int>& height);
};
