//
// Created by 张新 on 2022/9/10.
//
#include <vector>
#include <numeric>
using namespace std;

// 判断是否能将一个数组分割为两个子集,其和相等
bool canSplit(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1)
        return false;
    int target = sum / 2, n = nums.size();
    vector<bool> dp(target + 1); // 数组中的数能否凑成dp[i]
    dp[0] = true;
    for (int num : nums) {
        for (int i = target; i >= num; --i) {
            dp[i] = dp[i-num] || dp[i];
        }
    }
    return dp[target];
}
