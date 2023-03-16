#include "SolArraysHashing.h"

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

bool SolArraysHashing::containsDuplicate(std::vector<int>& nums) {
    bool result = false;
    std::sort(nums.begin(), nums.end());
    auto it = std::adjacent_find(nums.begin(), nums.end());

    if (it != nums.end()) {
        result = true;
    }

    return result;
}

bool SolArraysHashing::isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return (s == t);
}

vector<int> SolArraysHashing::twoSum(vector<int>& nums, int target) {
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

vector<vector<string>> SolArraysHashing::groupAnagrams(vector<string>& strs) {
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

vector<int> SolArraysHashing::topKFrequent(vector<int>& nums, int k) {
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

std::vector<int> SolArraysHashing::productExceptSelf(std::vector<int>& nums) {
    // use suffix/prefix approach
    int size = nums.size();
    std::vector<int> result(size, 1);

    // prefix
    int product = 1;
    for (int i = 1; i < size; i++) {
        product = product * nums[i - 1];
        result[i] = product;
    }
    // suffix
    product = 1;  // reset product
    for (int i = size - 2; i >= 0; i--) {
        product = product * nums[i + 1];
        result[i] = result[i] * product;
    }
    return result;
}

bool SolArraysHashing::isValidSudoku(vector<vector<char>>& board) {
    bool result = true;
    constexpr int SUDOKU_SIZE = 9;
    vector<vector<int>> columns{{}, {}, {}, {}, {}, {}, {}, {}, {}};
    vector<vector<int>> lines{{}, {}, {}, {}, {}, {}, {}, {}, {}};
    vector<vector<int>> squares{{}, {}, {}, {}, {}, {}, {}, {}, {}};

    // fill lines and columns vectors
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            int candidate{static_cast<int>(board[i][j]) - 48};

            int square_line_index = i / 3;
            int square_column_index = j / 3;
            int square_number = (square_line_index * 3) + square_column_index;
            if (candidate >= 0) {
                columns[j].push_back(candidate);
                lines[i].push_back(candidate);
                squares[square_number].push_back(candidate);
            }
        }
    }

    // detect duplicate in lines
    for (auto line : lines) {
        sort(line.begin(), line.end());
        auto it = std::adjacent_find(line.begin(), line.end());
        if (it != line.end()) {
            return false;
        }
    }

    // detect duplicate in columns
    for (auto column : columns) {
        sort(column.begin(), column.end());
        auto it = std::adjacent_find(column.begin(), column.end());
        if (it != column.end()) {
            return false;
        }
    }

    // detect duplicate in squares
    for (auto square : squares) {
        sort(square.begin(), square.end());
        auto it = std::adjacent_find(square.begin(), square.end());
        if (it != square.end()) {
            return false;
        }
    }

    return result;
}

int SolArraysHashing::longestConsecutive(vector<int>& nums) {
    int count = 1;
    int final_count = 0;

    if (nums.size() == 0) return 0;

    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1] + 1) {
            count++;
        } else if (nums[i] != nums[i - 1]) {
            final_count = max(final_count, count);
            count = 1;  // reset count
        }
    }
    final_count = max(final_count, count);
    return final_count;
}
