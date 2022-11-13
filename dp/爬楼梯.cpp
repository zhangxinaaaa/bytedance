//
// Created by 张新 on 2022/9/4.
//

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){return 1;}
        if(n == 2){return 2;}
        int a = 1, b = 2, temp;
        for(int i = 3; i <= n; i++){
            temp = a;
            a = b;
            b = temp + b;
        }
        return b;
    }
};