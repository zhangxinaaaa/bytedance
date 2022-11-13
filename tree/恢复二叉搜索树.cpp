//
// Created by 张新 on 2022/9/10.
//
#include "tree.h"
#include <algorithm>
using namespace std;
// 给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。

class Solution {
public:
    TreeNode *t1,*t2,*pre;
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(t1->val,t2->val);
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(pre!=nullptr&&pre->val>root->val){
            if(!t1) t1=pre;//如果未找到t1,更新t1
            t2=root;//如果t1已经被找到，更新t2即可
        }
        pre=root;
        inorder(root->right);
    }
};