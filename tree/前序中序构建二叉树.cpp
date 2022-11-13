//
// Created by 张新 on 2022/9/3.
//
#include <vector>
#include "tree.h"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return rebuildTree(preorder, inorder, 0, n-1, 0, n-1);
    }

    TreeNode* rebuildTree(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if (pl > pr) {
            return nullptr;
        }
        auto root = new TreeNode(preorder[pl]);
        int idx = il;
        while (inorder[idx] != root->val) {
            idx++;
        }
        root->left = rebuildTree(preorder, inorder, pl+1, pl+idx-il, il, idx-1);  // 左子树
        root->right = rebuildTree(preorder, inorder, pl+idx-il+1, pr, idx+1, ir); // 右子树
        return root;
    }
};