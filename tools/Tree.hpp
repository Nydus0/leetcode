#pragma once

#include <memory>
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

class Tree {
public:
    explicit Tree(const std::vector<int> &vals);

    [[nodiscard]] TreeNode* getRootNode() const;
    [[nodiscard]] std::vector<int> toVector() const;
    void print() const;

private:
    std::vector<std::unique_ptr<TreeNode> > _nodes;
};
