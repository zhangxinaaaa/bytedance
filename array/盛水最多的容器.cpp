//
// Created by 张新 on 2022/9/5.
//
#include <vector>
using namespace std;
#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(x,y) ((x)<(y)?(y):(x))

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1, res=0;
        while (l < r) {
            res = MAX(res, (r-l) * MIN(height[l], height[r]));
            if (height[l] < height[r]) {
                l = l + 1;
            }
            else
                r = r - 1;
        }
        return res;
    }
};