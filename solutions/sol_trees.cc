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
    static int max_depth = 0;

    if (root) {
        int incr_left = maxDepth(root->left);
        int incr_right = maxDepth(root->right);
        max_depth = max(incr_left, incr_right) + 1;
    } else {
        return 0;
    }

    return max_depth;
}