//
// Created by 张新 on 2022/9/5.
//
#include "array.h"

void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] > nums[j+1]) {
                int temp = nums[j];
                nums[j+1] = nums[j];
                nums[j] = temp;
                isSwap = true;
            }
        }
        if (!isSwap)
            return;
    }
}
