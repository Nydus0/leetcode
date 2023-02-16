#pragma once

#include <algorithm>
#include <map>
#include <string>
#include <vector>

class solution {
   public:
    bool containsDuplicate(std::vector<int>& nums);
    bool isAnagram(std::string s, std::string t);
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);
    std::vector<int> topKFrequent(std::vector<int>& nums, int k);
    std::vector<int> productExceptSelf(std::vector<int>& nums);
    bool isValidSudoku(std::vector<std::vector<char>>& board);
    int longestConsecutive(std::vector<int>& nums);

    void display_vector(std::vector<int> vec, std::string name);
    void display_map(std::map<int, int> map, std::string name);
};