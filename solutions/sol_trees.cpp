#include "sol_trees.hpp"

using namespace std;

node* sol_trees::invertTree(node* root) {
    // stop recursion
    if (!root) {
        return root;
    }

    // perform recursion
    invertTree(root->left);
    invertTree(root->right);

    // recursion action
    swap(root->left, root->right);

    return root;
}

int sol_trees::maxDepth(node* root) {
    if (root) {
        int incr_left = maxDepth(root->left);
        int incr_right = maxDepth(root->right);
        return max(incr_left, incr_right) + 1;
    } else {
        return 0;
    }

    return 0;
}

int sol_trees::diameterOfBinaryTree(node* root) {
    int diameter = 0;
    update_diameter(root, diameter);
    return diameter;
}

int sol_trees::update_diameter(node* root, int& diameter) {
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