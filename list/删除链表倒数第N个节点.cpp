//
// Created by 张新 on 2022/9/5.
//
#include "list.h"
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto slow = head, fast = head;
        for (int i=0; i<n; ++i) {
            fast = fast->next;
        }
        if (!fast)
            return head->next;

        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};