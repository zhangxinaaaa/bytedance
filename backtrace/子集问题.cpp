//
// Created by 张新 on 2022/9/4.
//
#include <vector>
using namespace std;

/*
 *
 * void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
 * */
// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    function<void(int)> dfs = [&](int idx) {
        if (idx > nums.size())
            return;
        res.push_back(cur);
        for(int i = idx; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(i + 1);
            cur.pop_back();
        }
    };
    dfs(0);
    return res;
}

// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    sort(nums.begin(), nums.end());
    function<void(int)> dfs = [&](int idx) {
        if (idx > nums.size()) // idx == num.size()时同样成立
            return ;
        res.push_back(cur);
        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i-1])
                continue;
            cur.push_back(nums[i]);
            dfs(i + 1);
            cur.pop_back();
        }
    };
    dfs(0);
    return res;
}

