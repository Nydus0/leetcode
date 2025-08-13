//
// Created by Nydus0 on 26/07/2025.
//

#include "solutions/trees.hpp"
#include "tools/node.hpp"

#include <gtest/gtest.h>

using namespace std;

TEST(trees, invert_tree) {
    vector nums = {1, 2, 3, 4, 5, 6};
    auto tree = Tree(nums);

    auto root = tree.getRootNode();
    invertTree(root);
    auto inverted = treeToVector(root);
    EXPECT_EQ(inverted, vector({1, 3, 2, 6, 5, 4}));
}