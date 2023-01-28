#include "solution.h"

#include <iostream>  // for debug
#include <map>
#include <unordered_map>

using namespace std;

bool solution::containsDuplicate(std::vector<int>& nums) {
    bool result = false;
    std::sort(nums.begin(), nums.end());
    auto it = std::adjacent_find(nums.begin(), nums.end());

    if (it != nums.end()) {
        result = true;
    }

    return result;
}

bool solution::isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return (s == t);
}

vector<int> solution::twoSum(vector<int>& nums, int target) {
    vector<int> result;

    for (int num_id = 0; num_id < nums.size(); num_id++) {
        for (int index = 0; index < nums.size(); index++) {
            if (num_id == index) {
                index++;
            } else {
                int sum = nums[num_id] + nums[index];
                if (sum == target) {
                    result.push_back(num_id);
                    result.push_back(index);
                    return result;
                }
            }
        }
    }

    return result;
}

vector<vector<string>> solution::groupAnagrams(vector<string>& strs) {
    std::unordered_map<string, vector<string>> map;

    for (int index = 0; index < strs.size(); index++) {
        string elt = strs[index];
        std::sort(strs[index].begin(), strs[index].end());
        map[strs[index]].push_back(elt);
    }

    vector<vector<string>> result;
    for (const auto& group : map) {
        result.push_back(group.second);
    }

    return result;
}

vector<int> solution::topKFrequent(vector<int>& nums, int k) {
    vector<int> result;
    vector<int> count;
    map<int, int> map;
    multimap<int, int, greater<int>> multimap;

    for (auto& elt : nums) {
        map[elt]++;
    }

    for (auto& elt : map) {
        // multimap (frequency / number)
        multimap.insert({elt.second, elt.first});
    }

    int fill_count = 0;
    for (auto& elt : multimap) {
        if (fill_count >= k) {
            return result;
        } else {
            result.push_back(elt.second);
        }
        fill_count++;
    }
    return result;
}

void solution::display_vector(std::vector<int> vec, string name) {
    cout << " -> vector " << name << "\n";

    for (int index = 0; index < vec.size(); index++) {
        cout << name << "[" << index << "] = " << vec[index] << "\n";
    }
}

void solution::display_map(std::map<int, int> map, std::string name) {
    cout << " -> map " << name << "\n";

    for (int index = 0; index < map.size(); index++) {
        cout << name << "[" << index << "] = " << map[index] << "\n";
    }
}