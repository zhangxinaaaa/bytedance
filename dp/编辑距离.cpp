//
// Created by 张新 on 2022/9/3.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(), n=word2.length();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dp(word1, word2, m-1, n-1, memo);
    }

    int dp(string& word1, string& word2, int i, int j, vector<vector<int>>& memo) {
        if (i==-1)
            return j+1; // 当word1为空时，插入word2中的全部字符
        if (j==-1)
            return i+1;  // 当word2为空时，删除word1中的全部字符
        if (memo[i][j] >= 0)
            return memo[i][j];
        if (word1[i] == word2[j])  // 当word[i] == word[j], 跳过当前字符
            return dp(word1, word2, i-1, j-1, memo);
        else {
            int tmpMin = min(dp(word1, word2, i-1, j, memo)+1, dp(word1, word2, i, j-1, memo)+1);  // 插入或者删除
            tmpMin = min(tmpMin, dp(word1, word2, i-1, j-1, memo)+1); // 替换
            memo[i][j] = tmpMin;
            return tmpMin;
        }
    }
};