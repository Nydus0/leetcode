#pragma once

#include "Solution.hpp"

class SolBinarySearch : public Solution {
   public:
    int search(std::vector<int>& nums, int target);
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);
};