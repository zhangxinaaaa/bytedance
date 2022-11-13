//
// Created by 张新 on 2022/9/11.
//
#include "tree.h"
#include <vector>
using namespace std;


int minDepth(TreeNode* root) {
    if (!root)
        return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    // 其中一颗子树为空， 取另一颗子树的深度
    return (left == 0 || right == 0) ? left + right + 1 : min(left, right) + 1;
}