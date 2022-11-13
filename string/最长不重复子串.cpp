//
// Created by 张新 on 2022/9/4.
//
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    static int longestSubString(const string& str) {
        unordered_map<char, int> mp;
        int left = 0, res = 0;
        for (int right = 0; right < str.length(); ++right) {
            char curChar = str[right];
            if (mp[curChar] > 0) {
                left = mp[curChar] + 1;
            }
            mp[curChar] = right;
            res = max(res, right - left + 1);
        }
        return res;
    }
};

// 时间复杂度O(n), 空间复杂度O(n)
int longestSubString(const string& str) {
    unordered_map<char, int> mp;
    int res = 1;
    int left = 0, right;   // [left, right]为最长的子串
    for (right = 0; right < str.size(); ++right) {
        char c = str[right];
        if (mp[c] > 0) { // 寻找当前子串上一次出现的位置
            left = mp[c] + 1;
        }
        mp[c] = right + 1; // 记录当前元素出现的位置
        res = max(res, right - left + 1);
    }
    return res;
}