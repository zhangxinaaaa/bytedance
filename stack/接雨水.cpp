//
// Created by 张新 on 2022/9/3.
//
#include <vector>
#include <stack>
using namespace std;

/*
当前高度小于等于栈顶高度，入栈，指针后移。
当前高度大于栈顶高度，出栈，计算出当前墙和栈顶的墙之间水的多少，
然后计算当前的高度和新栈的高度的关系，重复第 2 步。直到当前墙的高度不大于栈顶高度或者栈空，然后把当前墙入栈，指针后移。
 * */

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;
        for (int right=0; right < height.size(); right++) {
            while (!st.empty() && height[right] > height[st.top()]) {
                int h1 = height[st.top()];
                st.pop();
                if (st.empty())
                    break;
                int left = st.top();
                int h2 = min(height[left], height[right]);
                int h = h2 - h1;
                int w = right - left - 1;
                int cur = h * w;
                res = res + cur;
            }
            st.push(right);
        }
        return res;
    }
};