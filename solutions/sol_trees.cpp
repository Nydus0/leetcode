#include "sol_trees.hpp"

using namespace std;

node* sol_trees::invertTree(node* root) {

        //stop recursion
        if (!root) {
            return root;
        }

        //perform recursion
        invertTree(root->left);
        invertTree(root->right);

        //recursion action
        swap(root->left, root->right);

        return root;
}