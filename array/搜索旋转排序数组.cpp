//
// Created by 张新 on 2022/9/3.
//
#include "array.h"

int searchRotate(vector<int>& nums, int target) {
    if(nums.size() == 1)
        return nums[0] == target ? 0 : -1;
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[0] <= nums[mid])//左侧升序，= 保证只有两个数时，如果 l > r，也能输出正确答案
        {
            if(nums[mid] > target && nums[0] <= target)right = mid - 1;//确保目标在左侧
            else left = mid + 1; //继续划分
        }
        else//右侧升序
        {
            if(nums[mid] < target && nums[nums.size()-1] >= target)left = mid +1;//确保目标在右侧
            else right = mid - 1;
        }
    }
    return -1;
}