//
// Created by 张新 on 2022/9/4.
//
#include <vector>
using namespace std;

// 买卖一次
int buy_once(vector<int>& prices) {
    int buy = INT32_MIN, sell = 0;
    for (auto price : prices) {
        buy = max(buy, -price);
        sell = max(sell, buy + price);
    }
    return sell;
}

// 买卖两次
int buy_twice(vector<int>& prices) {
    int first_buy = INT32_MIN, first_sell = 0;
    int second_buy = INT32_MIN, second_sell = 0;
    for(int price : prices) {
        first_buy = max(first_buy, -price);
        first_sell = max(first_sell, first_buy + price);
        second_buy = max(second_buy, first_sell - price);
        second_sell = max(second_sell, second_buy + price);
    }
    return second_sell;
}

// 买卖多次
int maxProfit(vector<int>& prices){
    int buy = INT32_MIN, sell = 0;
    for (int price : prices) {
        int buy_now = max(buy, sell - price);
        int sell_now = max(sell, buy + price);
        buy = buy_now;
        sell = sell_now;
    }
    return sell;
}

// 买卖含手续费
int buy_x(vector<int>& prices, int fee) {
    int buy = INT_MIN, sell = 0;
    // 在买入或卖出时减去手续费即可
    for (auto& p : prices)
    {
        int buynow = max(buy, sell - p - fee);
        int sellnow = max(sell, buy + p);
        buy = buynow;
        sell = sellnow;
    }

    return sell;
}

// 买卖含冻结期
int buy_xx(vector<int>& prices) {
    int buy = -prices[0], sell = 0, lock = 0;
    // 因为有冷冻期，所以定义变量 lock 表示无法交易的时候
    for (auto& p : prices)
    {
        int buynow = max(buy, lock - p);
        int sellnow = max(sell, buy + p);
        lock = sell;
        buy = buynow;
        sell = sellnow;
    }
    return sell;
}