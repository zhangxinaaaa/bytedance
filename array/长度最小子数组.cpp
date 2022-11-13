//
// Created by 张新 on 2022/9/4.
//
#include "array.h"
// 给定一个含有 n 个正整数的数组和一个正整数 target 。

// 找出该数组中满足其和 ≥ target 的长度最小的
// 连续子数组[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

int minSubArrayLen(int s, vector<int>& nums) {
    int result = INT32_MAX; // 最终的结果
    int sum = 0; // 子序列的数值之和
    int subLength = 0; // 子序列的长度
    for (int i = 0; i < nums.size(); i++) { // 设置子序列起点为i
        sum = 0;
        for (int j = i; j < nums.size(); j++) { // 设置子序列终止位置为j
            sum += nums[j];
            if (sum >= s) { // 一旦发现子序列和超过了s，更新result
                subLength = j - i + 1; // 取子序列的长度
                result = result < subLength ? result : subLength;
                break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
            }
        }
    }
    // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
    return result == INT32_MAX ? 0 : result;
}