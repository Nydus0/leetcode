#pragma once

#include "solution.hpp"

class sol_binary_search : public solution {
   public:
    int search(std::vector<int>& nums, int target);
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);
    int minEatingSpeed(std::vector<int>& piles, int h);
    int findMin(std::vector<int>& nums);
    int search_in_rotated_array(std::vector<int>& nums, int target);
};
