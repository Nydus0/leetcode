#pragma once

#include <map>
#include <string>
#include <vector>

class Solution {
   public:
    void display_vector(std::vector<int> vec, std::string name);
    void display_map(std::map<int, int> map, std::string name);
    void display_string(std::string str, std::string name);
};