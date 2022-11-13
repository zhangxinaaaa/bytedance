//
// Created by 张新 on 2022/9/4.
//
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int len=INT_MAX, cur=0;
        map<char, int> window, target;
        for (int i=0; i<t.length(); i++)
            target[t[i]]++;
        int need = target.size();
        int left=0, right=0, start=0;
        while (right < s.length()) {
            char curChar = s[right++];
            if (target.count(curChar)) {
                window[curChar]++;
                if (window[curChar] == target[curChar])
                    cur++;
            }
            while (cur == need) {
                if (right - left < len) {  // 当前区间小于结果长度
                    len = right - left;
                    start = left;
                }
                char curCharLef = s[left++];
                if (target.count(curCharLef)) {
                    if (window[curCharLef] == target[curCharLef])
                        cur--;
                    window[curCharLef]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};


