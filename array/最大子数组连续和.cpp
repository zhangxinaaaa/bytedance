//
// Created by 张新 on 2022/9/3.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int dp = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            dp = max(nums[i], dp + nums[i]);
            res = max(dp, res);
        }
        return res;
    }
};

// 时间复杂度 O(n)
int maxSubArray(vector<int>& nums) {
    int res = nums[0];
    int dp = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        dp = max(dp, dp + nums[i]);
        res = max(dp, res);
    }
    return res;
}