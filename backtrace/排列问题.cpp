//
// Created by 张新 on 2022/9/4.
//

#include <vector>

using namespace std;
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    function<void()> dfs = [&]() {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int & num : nums) {
            if (count(cur.begin(), cur.end(), num))
                continue;
            cur.push_back(num);
            dfs();
            cur.pop_back();
        }
    };
    dfs();
    return res;
}

// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
// https://img-blog.csdnimg.cn/20201124201331223.png
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> visited(nums.size());
    sort(nums.begin(), nums.end());
    function<void()> dfs = [&]() {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1]))
                continue;
            visited[i] = true;
            cur.push_back(nums[i]);
            dfs();
            cur.pop_back();
            visited[i] = false;
        }
    };
    dfs();
    return res;
}
