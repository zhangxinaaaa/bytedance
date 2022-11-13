//
// Created by 张新 on 2022/9/4.
//
#include <string>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0 ,j = 0;
        while(i < version1.size() || j < version2.size())
        {
            int a = 0, b = 0;
            while(i < version1.size() && version1[i] != '.') a = a * 10 + version1[i++] - '0';
            while(j < version2.size() && version2[j] != '.') b = b * 10 + version2[j++] - '0';
            if (a > b) return 1;
            else if (a < b) return -1;
            i++;
            j++;
        }
        return 0;
    }
};