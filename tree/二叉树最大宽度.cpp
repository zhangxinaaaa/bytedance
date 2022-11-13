//
// Created by 张新 on 2022/9/4.
//
#include "tree.h"
#include <queue>
using namespace std;

// 给你一棵二叉树的根节点 root ，返回树的 最大宽度 。
//
// 树的 最大宽度 是所有层中最大的 宽度 。
//
// 每一层的 宽度 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。将这个二叉树视作与满二叉树结构相同，
// 两端点间会出现一些延伸到这一层的 null 节点，这些 null 节点也计入长度。


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)    return 0;
        queue<pair<TreeNode*, int>> q;  //pair的第二个位置记录当前是第几个节点
        q.push({root, 1});
        int width = 0;
        while(!q.empty())
        {
            int count = q.size();
            int start = q.front().second, index; //start是本层起点, index是本层当前遍历到的节点的索引
            while(count--)
            {
                TreeNode *tmp = q.front().first;
                index = q.front().second;
                q.pop();
                if(tmp->left)   q.push({tmp->left , index * 2 - start * 2});  //防止索引位置太大溢出
                if(tmp->right)  q.push({tmp->right, index * 2 + 1 - start * 2});
            }
            width = max(width, index - start + 1);
        }
        return width;
    }
};