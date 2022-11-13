//
// Created by 张新 on 2022/9/5.
//

int mySqrt(int x) {
    if (x == 0)
        return 0;
    int left = 1, right = x;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int sqrt = x / mid;
        if (sqrt == mid) {
            return mid;
        } else if (sqrt > mid) {
            left = mid + 1;
        } else
            right = mid - 1;
    }
    return left - 1;
}