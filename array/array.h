//
// Created by 张新 on 2022/9/5.
//

#ifndef BYTEDANCE_ARRAY_H
#define BYTEDANCE_ARRAY_H
#include <vector>
using namespace std;

// 排序问题
void bubbleSort(vector<int>& nums); // 冒泡排序 O(n^2)
void quickSort(vector<int>& nums, int left, int right); // 快速排序 O(n log(n))

// 快排/优先队列
int findKthNumber(vector<int>& nums, int k); // O(n)

// 二分
int binarySearch(vector<int>& nums, int target); // 二分查找 O(log(n))
int findPeakElement(vector<int>& nums); // 峰值元素O (log(n))
int mySqrt(int x); //算术平方根 O(log(n))

// 滑动窗口
vector<vector<int>> threeSum(vector<int>& nums); // 三数之和 O(n^2)
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals); // 合并区间

// 其他
void nextPermutation(vector<int>& nums); // 下一个排列
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2); // 寻找两个正序数组中位数
bool searchMatrix(vector<vector<int>>& matrix, int target); // 搜索二维数组
int firstMissingPositive(vector<int>& nums); // 第一个缺失的正数
int minSubArrayLen(int s, vector<int>& nums); // 长度最小子数组
vector<int> spiralOrder(vector<vector<int>>& matrix); //顺时针遍历矩阵

#endif //BYTEDANCE_ARRAY_H
