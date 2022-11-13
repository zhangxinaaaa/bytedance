//
// Created by 张新 on 2022/9/3.
//
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};


// [1, 2, 3, 4, 5] -> [1, 5, 2, 4, 3]
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head)
            return;
        vector<ListNode*> vec;
        auto cur = head;
        while (cur) {
            vec.push_back(cur);
            cur = cur->next;
        }
        int left = 0, right = vec.size() - 1;
        while (left < right) {
            vec[left]->next = vec[right];
            vec[right--]->next = vec[++left];
        }
        vec[left]->next = nullptr;
    }
};