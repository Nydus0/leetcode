#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

class solution {
   public:
    template <typename T>
    void display(const T& container, std::string name) {
        std::cout << name << ": ";
        for (const auto& elt : container) {
            std::cout << elt << " ";
        }
        std::cout << "\n";
    }

    template <typename T>
    void detailed_display(const T& container, std::string name) {
        std::cout << name << ": ";

        unsigned int index = 0;
        for (unsigned int index = 0; index < container.size(); index++) {
            std::cout << name << "[" << index << "] = " << container[index] << "\n";
        }
    }
};