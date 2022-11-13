//
// Created by 张新 on 2022/9/3.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string res = "";
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int len=0; len<n; len++) {
            for (int i=0; i+len<n; i++) {
                if (len == 0) {
                    dp[i][i] = true;
                } else if (len == 1 || len == 2) {
                    dp[i][i+len] = s[i] == s[i+len];
                } else {
                    dp[i][i+len] = dp[i+1][i+len-1] && s[i] == s[i+len];
                }
                if (dp[i][i+len] && len+1 > res.length()) {
                    res = s.substr(i, len+1);
                }
            }
        }
        return res;
    }
};