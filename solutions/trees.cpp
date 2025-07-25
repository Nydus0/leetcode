#include "solutions/trees.hpp"

#include <algorithm>

using namespace std;

node* invertTree(node* root) {
    // stop recursion
    if (!root) {
        return root;
    }

    // perform recursion
    invertTree(root->left);
    invertTree(root->right);

    // recursion action
    std::swap(root->left, root->right);

    return root;
}

int maxDepth(node* root) {
    if (root) {
        int incr_left = maxDepth(root->left);
        int incr_right = maxDepth(root->right);
        return max(incr_left, incr_right) + 1;
    } else {
        return 0;
    }

    return 0;
}

int diameterOfBinaryTree(node* root) {
    int diameter = 0;
    update_diameter(root, diameter);
    return diameter;
}

int update_diameter(node* root, int& diameter) {
    // stop recursion
    if (!root) {
        return 0;
    }

    // recursion action
    int left_height = update_diameter(root->left, diameter);
    int right_height = update_diameter(root->right, diameter);
    diameter = max(left_height + right_height, diameter);

    return max(left_height, right_height) + 1;
}