#pragma once

#include "solution.hpp"

#include <string>
#include <unordered_map>

class sol_binary_search : public solution {
   public:
    int search(std::vector<int>& nums, int target);
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);
    int minEatingSpeed(std::vector<int>& piles, int h);
    int findMin(std::vector<int>& nums);
    int search_in_rotated_array(std::vector<int>& nums, int target);
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

class TimeMap {
   public:
    TimeMap();

    void set(std::string key, std::string value, int timestamp);
    std::string get(std::string key, int timestamp);

   private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> _hashmap;
};