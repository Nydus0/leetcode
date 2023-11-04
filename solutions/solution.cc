#include "solution.hpp"

#include <iostream>

using namespace std;

void solution::display_vector(vector<int> vec, string name) {
    cout << " -> vector " << name << "\n";

    for (int index = 0; index < vec.size(); index++) {
        cout << name << "[" << index << "] = " << vec[index] << "\n";
    }
}

void solution::display_map(map<int, int> map, string name) {
    cout << " -> map " << name << "\n";

    for (int index = 0; index < map.size(); index++) {
        cout << name << "[" << index << "] = " << map[index] << "\n";
    }
}

void solution::display_string(string str, string name) {
    cout << " -> string " << name << "\n";

    for (int index = 0; index < str.size(); index++) {
        cout << name << "[" << index << "] = " << str[index] << "\n";
    }
}

template <>
void solution::display<vector<int>>(vector<int> container, string name) {
    display_vector(container, name);
}
template <>
void solution::display<map<int, int>>(map<int, int> container, string name) {
    display_map(container, name);
}
template <>
void solution::display<string>(string container, string name) {
    display_string(container, name);
}
