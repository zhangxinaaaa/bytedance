//
// Created by 张新 on 2022/9/10.
//
#include "tree.h"
#include <vector>
#include <algorithm>
using namespace std;

void create_bs_tree(TreeNode *root, TreeNode *bs_root) {
    if (bs_root == nullptr) {
        auto node = new TreeNode(root->val);
        bs_root = node;
        return;
    }
    if (root->val > bs_root->val)
        create_bs_tree(root, bs_root->right);
    if (root->val < bs_root->val)
        create_bs_tree(root, bs_root->left);
}


void preorder(TreeNode* root, TreeNode* bs_root) {
    if (!root)
        return;
    create_bs_tree(root, bs_root);
    preorder(root->left, bs_root);
    preorder(root->right, bs_root);
}

TreeNode* sol_iter(TreeNode* root) {
    auto bs_root = nullptr;
    preorder(root, bs_root);
    return bs_root;
}

void pre_insert(TreeNode* root, vector<TreeNode*>& vec) {
    if (!root)
        return;
    vec.push_back(root);
    pre_insert(root->left, vec);
    pre_insert(root->right, vec);
}

TreeNode* sol_sort(TreeNode* root) {
    auto cmp = [](TreeNode* t1, TreeNode* t2) {return t1->val <= t2->val;};
    vector<TreeNode*> vec;
    pre_insert(root, vec);
    sort(vec.begin(), vec.end(), cmp);
}
