//
// Created by 张新 on 2022/9/4.
//
#include "tree.h"
#include <vector>
using namespace std;
// 判断是否存在路径

class Solution {
public:
    void pathSum(vector<vector<int>>& res, vector<int>& cur, TreeNode* root, int target) {
        if (!root)
            return;
        cur.push_back(root->val);
        if (!root->left && !root->right) {
            if (root->val == target) {
                res.push_back(cur);
                return;
            }
            return;
        }
        pathSum(res, cur, root->left, target - root->val);
        pathSum(res, cur, root->right, target - root->val);
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> cur;
        pathSum(res, cur, root, targetSum);
        return res;
    }
};