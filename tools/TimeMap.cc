
#include "TimeMap.hpp"

#include <algorithm>

using namespace std;

void TimeMap::set(string key, string value, int timestamp) {
    _hashmap[key].push_back(make_pair(value, timestamp));
}

string TimeMap::get(string key, int timestamp) {
    // all the timestamps are strictly increasing so we can directly use binary search on timestamps
    // user upper_bound : we want 1st elt verifying elt.timestamp > timestamp
    auto it = upper_bound(_hashmap[key].begin(), _hashmap[key].end(), pair<string, int>("", timestamp),
                          // create lambda to specialize comparison with timestamp => comp(value, element)
                          [](const pair<string, int>& pair_a, const pair<string, int>& pair_b) {
                              return pair_a.second < pair_b.second;
                          });

    // return value of elt just before result of binary search
    return (it == _hashmap[key].begin()) ? "" : prev(it)->first;
}