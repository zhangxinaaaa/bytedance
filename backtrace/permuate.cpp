//
// Created by 张新 on 2022/9/2.
//
#include <vector>

using namespace std;

void dfs(vector<int>& nums, vector<int>& curNums, vector<vector<int>>& res, int n) {
    if (n == 0)
        res.push_back(curNums);
    for (int i=0; i<nums.size(); i++) {
        if (count(curNums.begin(), curNums.end(), nums[i]))
            continue;
        curNums.push_back(nums[i]);
        dfs(nums, curNums, res, n-1);
        curNums.pop_back();
    }
}

// 全排列
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> curNums;
    dfs(nums, curNums, res, nums.size());
    return res;
}