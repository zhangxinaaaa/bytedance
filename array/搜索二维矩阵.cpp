//
// Created by 张新 on 2022/9/4.
//
#include "array.h"

// 编写一个高效的算法来搜索 mx n矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
//
//每行的元素从左到右升序排列。
//每列的元素从上到下升序排列。
//

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0)
        return false;
    int n = matrix[0].size();
    int i = 0, j = n - 1;
    while (matrix[i][j] != target) {
        if (matrix[i][j] > target) {
            j -= 1;
        } else {
            i += 1;
        }
        if (i < 0 || i == m || j < 0 || j == n)
            return false;
    }
    return true;
}
