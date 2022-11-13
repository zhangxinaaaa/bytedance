//
// Created by 张新 on 2022/9/7.
//
#include "tree.h"
#include <unordered_map>
using namespace std;

// O(N)

//根据以上定义，若 root 是 p,q 的 最近公共祖先 ，则只可能为以下情况之一：
//p 和 q 在 root 的子树中，且分列 root 的 异侧（即分别在左、右子树中）；
// p=root ，且 q 在 root 的左或右子树中 ；
// q=root ，且 p 在 root 的左或右子树中 ；
//因此，考虑通过递归对二叉树进行后序遍历，
// 当遇到节点 p 或 q 时返回。从底至顶回溯，当节点 p, q 在节点 root 的异侧时，节点 root 即为最近公共祖先，则向上返回 root 。

// 根据left 和 right 的值，可分为四种情况：
// 1. left 和 right 同时为空 ：说明 root 的左 / 右子树中都不包含 p,q ，返回 null ；
// 2. left 和 right 同时不为空 ：说明 p,q 分列在 root 的 异侧（分别在 左 / 右子树），因此 root 为最近公共祖先，返回 root ；
// 3. left 为空 ，right 不为空 ：p,q 都不在 root 的左子树中，直接返回 right 。具体可分为两种情况：
// p,q 其中一个在 root 的 右子树 中，此时 right 指向 p（假设为 p ）；
// p,q 两节点都在 root 的 右子树 中，此时的 right 指向 最近公共祖先节点 ；
// 4. left 不为空 ， right 为空 ：与情况 3. 同理；

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left == nullptr) return right;
    if(right == nullptr) return left;
    return root;
}