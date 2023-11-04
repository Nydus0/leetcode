#pragma once

#include <string>
#include <unordered_map>
#include <vector>

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

class TimeMap {
   public:
    TimeMap() = default;

    void set(std::string key, std::string value, int timestamp);
    std::string get(std::string key, int timestamp);

   private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> _hashmap;
};