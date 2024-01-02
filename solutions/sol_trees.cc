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
    if (root) { ++max_depth; } else { return max_depth;}

    //stop recursion
    maxDepth(root->left);
    maxDepth(root->right);


    // perform recursion
    


    // recursion action




}