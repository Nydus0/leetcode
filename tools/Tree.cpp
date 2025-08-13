//
// Created by Nydus0 on 12/08/2025.
//

#include "tools/Tree.hpp"

#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

Tree::Tree(const std::vector<int> &vals) {
    if (vals.empty()) return;

    _nodes.emplace_back(make_unique<TreeNode>(vals[0]));
    auto root = _nodes[0].get();

    std::queue<TreeNode*> q;
    q.push(root);

    size_t node_index = 1;
    while (node_index < vals.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (node_index < vals.size()) {
            _nodes.emplace_back(make_unique<TreeNode>(vals[node_index]));
            current->left = _nodes[node_index++].get();
            q.push(current->left);
        }
        if (node_index < vals.size()) {
            _nodes.emplace_back(make_unique<TreeNode>(vals[node_index]));
            current->right = _nodes[node_index++].get();
            q.push(current->right);
        }
    }
}

TreeNode* Tree::getRootNode() const {
    return _nodes[0].get();
}

std::vector<int> Tree::toVector() const {
    std::vector<int> result;
    if (_nodes.empty()) return result;

    std::queue<TreeNode*> q;
    q.push(getRootNode());

    while (!q.empty()) {
        const TreeNode* node = q.front();
        q.pop();
        if (node) {
            result.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        } else {
            // If you want to keep null placeholders for exact shape:
            // result.push_back(INT_MIN); // or some sentinel
        }
    }

    return result;
}

void Tree::print() const {
    if (_nodes.empty()) return;

    const auto root = getRootNode();

    // Compute height
    std::function<int(TreeNode *)> heightFn = [&](const TreeNode *node) {
        if (!node) return 0;
        return 1 + std::max(heightFn(node->left), heightFn(node->right));
    };
    const int height = heightFn(root);

    const int maxWidth = std::pow(2, height) - 1;
    std::vector levelNodes = {root};

    for (int level = 0; level < height; level++) {
        const int spacing = maxWidth / std::pow(2, level + 1);

        // Print node values
        std::cout << std::setw(spacing + 1) << "";
        for (size_t i = 0; i < levelNodes.size(); i++) {
            if (levelNodes[i])
                std::cout << levelNodes[i]->val;
            else
                std::cout << " ";
            if (i < levelNodes.size() - 1)
                std::cout << std::setw(spacing * 2 + 1) << "";
        }
        std::cout << "\n";

        // Print branches
        if (level < height - 1) {
            for (int b = 1; b <= spacing; b++) {
                std::cout << std::setw(spacing - b + 1) << "";
                for (size_t i = 0; i < levelNodes.size(); i++) {
                    if (levelNodes[i]) {
                        std::cout << (levelNodes[i]->left ? "/" : " ");
                        std::cout << std::setw(b * 2 - 1) << "";
                        std::cout << (levelNodes[i]->right ? "\\" : " ");
                    } else {
                        std::cout << " " << std::setw(b * 2 - 1) << "" << " ";
                    }
                    if (i < levelNodes.size() - 1)
                        std::cout << std::setw(spacing * 2 - b * 2 + 1) << "";
                }
                std::cout << "\n";
            }
        }

        // Build next level
        std::vector<TreeNode *> nextLevel;
        for (auto node: levelNodes) {
            if (node) {
                nextLevel.push_back(node->left);
                nextLevel.push_back(node->right);
            } else {
                nextLevel.push_back(nullptr);
                nextLevel.push_back(nullptr);
            }
        }
        levelNodes.swap(nextLevel);
    }
}

