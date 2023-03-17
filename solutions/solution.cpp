#include "Solution.hpp"

#include <iostream>

using namespace std;

void Solution::display_vector(std::vector<int> vec, string name) {
    cout << " -> vector " << name << "\n";

    for (int index = 0; index < vec.size(); index++) {
        cout << name << "[" << index << "] = " << vec[index] << "\n";
    }
}

void Solution::display_map(std::map<int, int> map, std::string name) {
    cout << " -> map " << name << "\n";

    for (int index = 0; index < map.size(); index++) {
        cout << name << "[" << index << "] = " << map[index] << "\n";
    }
}

void Solution::display_string(std::string str, std::string name) {
    cout << " -> string " << name << "\n";

    for (int index = 0; index < str.size(); index++) {
        cout << name << "[" << index << "] = " << str[index] << "\n";
    }
}