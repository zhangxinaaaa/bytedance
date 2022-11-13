#include "array.h"

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int left = intervals[0][0], right = intervals[0][1];
    vector<vector<int>> res;
    for (int i=1; i<intervals.size(); i++) {
        if (intervals[i][0] <= right) {
            left = min(left, intervals[i][0]);
            right = max(right, intervals[i][1]);
        } else {
            res.push_back(vector<int>{left, right});
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }
    res.push_back(vector<int>{left, right});
    return res;
}

// 时间复杂度O(n log(n))
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int left = intervals[0][0], right = intervals[0][1];
    vector<vector<int>> res;
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= right) {
            left = min(left, intervals[i][0]);
            right = max(right, intervals[i][1]);
        } else {
            res.push_back(vector<int>{left, right});
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }
    res.push_back(vector<int>{left, right});
    return res;
}