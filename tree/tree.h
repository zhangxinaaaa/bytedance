//
// Created by 张新 on 2022/9/3.
//

#ifndef BYTEDANCE_TREE_H
#define BYTEDANCE_TREE_H

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() { val = 0, left = nullptr, right = nullptr;}
    TreeNode(int x): val(x) { left = nullptr, right = nullptr;}
};

#endif //BYTEDANCE_TREE_H
