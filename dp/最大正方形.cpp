//
// Created by 张新 on 2022/9/3.
//
#include <vector>
using namespace std;

// dp[i][j]表示以第i行第j列为右下角所能构成的最大正方形边长, 则递推式为:
// dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (matrix[i-1][j-1] == '1') { // 数组长度为+1时，索引需要减一
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};