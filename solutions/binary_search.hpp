#pragma once

#include <string>
#include <unordered_map>
#include <vector>

int binSearch(std::vector<int> &nums, int target);
bool searchMatrix(std::vector<std::vector<int> > &matrix, int target);
int minEatingSpeed(std::vector<int> &piles, int h);
int findMin(std::vector<int> &nums);
int searchInRotatedArray(std::vector<int> &nums, int target);

class TimeMap {
    /**
    * Your TimeMap object will be instantiated and called as such:
    * TimeMap* obj = new TimeMap();
    * obj->set(key,value,timestamp);
    * string param_2 = obj->get(key,timestamp);
    */

public:
    void set(std::string key, std::string value, int timestamp);
    std::string get(std::string key, int timestamp);

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int> > > _hashmap;
};
