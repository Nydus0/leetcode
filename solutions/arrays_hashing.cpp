#include "solutions/arrays_hashing.hpp"

#include <algorithm>
#include <map>
#include <ranges>

using namespace std;

bool containsDuplicate(std::vector<int>& nums) {
    bool result = false;
    ranges::sort(nums);
    auto it = ranges::adjacent_find(nums);

    if (it != nums.end()) {
        result = true;
    }

    return result;
}

bool isAnagram(string s, string t) {
    return ranges::is_permutation(s, t);
    /** other solution (use ranges::sort) :
     *
     * ranges::sort(s);
     * ranges::sort(s);
     * return (s == t);
     *
     * ***/
}

vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result;

    for (int num_id = 0; num_id < nums.size(); num_id++) {
        for (int index = num_id + 1; index < nums.size(); index++) {
            if (nums[num_id] + nums[index] == target) {
                return {num_id, index};
            }
        }
    }

    return result;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::map<string, vector<string>> map;

    for (auto & str : strs) {
        string elt = str;
        ranges::sort(str);
        map[str].emplace_back(elt);
    }

    vector<vector<string>> result;
    for (const auto &val: map | views::values) {
        result.push_back(val);
    }

    return result;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;
    map<int, int> map;
    vector<pair<int,int>> vec;

    for (auto& elt : nums) {
        map[elt]++;
    }

    for (auto&[fst, snd] : map) {
        // vector (frequency / number)
        vec.emplace_back(snd, fst);
    }

    ranges::sort(vec, greater());

    int count = 0;
    for (auto &val: vec | views::values) {
        if (count >= k) {
            return result;
        }
        result.push_back(val);
        count++;
    }
    return result;
}

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    // use suffix/prefix approach
    const int size = static_cast<int>(nums.size());
    std::vector result(size, 1);

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

bool isValidSudoku(vector<vector<char>>& board) {
    constexpr bool result = true;
    constexpr int SUDOKU_SIZE = 9;
    vector<vector<int>> columns(SUDOKU_SIZE);
    vector<vector<int>> lines(SUDOKU_SIZE);
    vector<vector<int>> squares(SUDOKU_SIZE);

    // fill lines and columns vectors
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            int candidate{static_cast<int>(board[i][j]) - 48};

            const int square_line_index = i / 3;
            const int square_column_index = j / 3;
            const int square_number = (square_line_index * 3) + square_column_index;
            if (candidate >= 0) {
                columns[j].push_back(candidate);
                lines[i].push_back(candidate);
                squares[square_number].push_back(candidate);
            }
        }
    }

    // detect duplicate in lines
    for (auto line : lines) {
        ranges::sort(line);
        auto it = ranges::adjacent_find(line);
        if (it != line.end()) {
            return false;
        }
    }

    // detect duplicate in columns
    for (auto column : columns) {
        ranges::sort(column);
        auto it = ranges::adjacent_find(column);
        if (it != column.end()) {
            return false;
        }
    }

    // detect duplicate in squares
    for (auto square : squares) {
        ranges::sort(square);
        auto it = ranges::adjacent_find(square);
        if (it != square.end()) {
            return false;
        }
    }

    return result;
}

int longestConsecutive(vector<int>& nums) {
    int count = 1;
    int final_count = 0;

    if (nums.empty()) return 0;

    ranges::sort(nums);

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
