#pragma once

#include "../tools/node.hpp"
#include "solution.hpp"

class sol_trees : public solution {
   public:
    node* invertTree(node* root);
    int maxDepth(node* root);
    int diameterOfBinaryTree(node* root);

   private:
    int update_diameter(node* root, int& diameter);
};