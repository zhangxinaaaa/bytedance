//
// Created by 张新 on 2022/9/4.
//
#include <vector>
using namespace std;

// 组合总数
// 给你一个 无重复元素 的整数数组candidates 和一个目标整数target，找出candidates中可以使数字和为目标数target 的 所有不同组合 ，
// 并以列表形式返回。你可以按 任意顺序 返回这些组合。
// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。

class Sol1 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int, int)> dfs = [&](int idx, int target) {
            if (target == 0)
                res.push_back(cur);
            else if (target < 0)
                return ;
            else {
                for (int i = idx; i < candidates.size(); ++i) {
                    cur.push_back(candidates[i]);
                    dfs(i, target - candidates[i]);
                    cur.pop_back();
                }
            }
        };
        dfs(0, target);
        return res;
    }

};

// 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的每个数字在每个组合中只能使用 一次
class Sol2 {
public:
    static vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> res;
        function<void(int, int)> dfs = [&](int idx, int target) {
            if (target < 0)
                return ;
            else if (target == 0) {
                res.push_back(cur);
            } else {
                for (int i = idx; i < candidates.size(); ) {
                    cur.push_back(candidates[i]);
                    dfs(i + 1, target - candidates[i]);
                    cur.pop_back();
                    int val = candidates[i];
                    while (i < candidates.size() && candidates[i] == val)
                        i++;
                }
            }
        };
        dfs(0, target);
        return res;
    }
};