#pragma once

class node {
    public:
    int val;
    node *left;
    node *right;
    node() : val(0), left(nullptr), right(nullptr) {}
    node(int x) : val(x), left(nullptr), right(nullptr) {}
    node(int x, node *left, node *right) : val(x), left(left), right(right) {}
};