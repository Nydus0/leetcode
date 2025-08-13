#pragma once

#include <vector>

class TreeNode {
   public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* vectorToTree(const std::vector<int>& nums);
std::vector<int> treeToVector(TreeNode* root);

void printTreeTopDown(TreeNode* root);


