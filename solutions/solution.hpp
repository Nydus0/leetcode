#pragma once

#include <iostream>
#include <string>

template <typename T>
static void display(const T& container, std::string name) {
    std::cout << name << ": ";
    for (const auto& elt : container) {
        std::cout << elt << " ";
    }
    std::cout << "\n";
}

template <typename T>
static void detailed_display(const T& container, std::string name) {
    std::cout << name << ": ";

    unsigned int index = 0;
    for (unsigned int index = 0; index < container.size(); index++) {
        std::cout << name <<  "[" << index << "] = " << container[index] << "\n";
    }
}

class solution {}; //no implementation for now