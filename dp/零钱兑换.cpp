//
// Created by 张新 on 2022/9/10.
//
#include <vector>
using namespace std;

// 零钱兑换：给定amount,求用任意数量不同面值的零钱换到amount所用的最少数量
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] = min(dp[i-coin] + 1, dp[i]);
        }
    }
    return dp[amount] == amount+1 ? -1 : dp[amount];
}

// 零钱兑换2：任选硬币凑成指定金额,求组合总数
int change(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int i=coin; i <= amount; ++i) {
            dp[i] += dp[i-coin];
        }
    }
    return dp[amount];
}