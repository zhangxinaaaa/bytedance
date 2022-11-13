//
// Created by 张新 on 2022/9/3.
//

/*
 * 递归，对于节点root来说，假设左子树和右子树最大路径长度分别为：maxL，maxR。
 * 则以root为根的二叉树最大路径长度=max{maxL，maxR，root，maxL+root，maxR+root，maxL+maxR+root}。
 * 用这6个值得最大值更新ans。
 * */
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
    int res = -999;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root,0);
        return res;
    }

    int dfs(TreeNode* root, int sum){
        if(root == nullptr){
            return 0;
        }
        int left=dfs(root->left,sum+root->val);
        int right=dfs(root->right,sum+root->val);
        left = max(0,left);
        right = max(0,right);
        res = max(res,root->val + left + right);
        return max(left,right)+root->val;
    }
};