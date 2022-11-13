//
// Created by 张新 on 2022/9/4.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int res = 0;
        vector<int> dp(n);
        for (int i=0; i<n; i++) {
            if (s[i] == ')') {
                if (i > 0 && s[i-1] == '(') {
                    dp[i] = 2;
                    if (i -1 > 0)
                        dp[i] += dp[i-2];
                } else {
                    if (i>0 && i - dp[i-1] -1 >= 0 && s[i - dp[i-1]-1] == '(') {
                        dp[i] = dp[i-1] + 2;
                        if (i - dp[i-1] - 2 >= 0)
                            dp[i] += dp[i - dp[i-1] -2];
                    }
                }
            }
            if (dp[i] > res)
                res = dp[i];
        }
        return res;
    }
};