//
// Created by 张新 on 2022/9/5.
//
#include "array.h"
#include <stack>

void quickSort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int i = left, j = right, x = nums[left];
        while (i < j) {
            while (i < j && nums[j] >= x)
                j--;
            if (i < j)
                nums[i++] = nums[j];
            while (i < j && nums[i] < x)
                i++;
            if (i < j)
                nums[j--] = nums[i];
        }
        nums[i] = x;
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }
}

// n个整数的无序数组，找到每个元素后面比它大的第一个数
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) { // 从左到右遍历数组
        while (!st.empty() && nums[st.top()] < nums[i]) { // 如果栈不为空且栈顶元素小于当前元素
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
