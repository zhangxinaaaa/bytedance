//
// Created by 张新 on 2022/9/6.
//
#include "array.h"

int division(vector<int>& nums, int left, int right) {
    int base = nums[left];
    while (left < right) {
        while (left < right && nums[right] >= base)
            right--;
        nums[left] = nums[right];
        while (left < right && nums[left] <= base)
            left++;
        nums[right] = nums[left];
    }
    nums[left] = base;
    return left;
}

int findKthNumber(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k)
        return -1;
    int left = 0, right = n-1;
    while (left <= right) {
        int base = division(nums, left, right);
        if (n - base == k) {
            return base;
        } else if (n - base > k) {
            left = base + 1;
        } else {
            right = base - 1;
        }
    }
    return -1;
}

