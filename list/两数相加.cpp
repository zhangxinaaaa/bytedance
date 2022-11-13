#include "list.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* tail = res;
        int forward = 0;
        while(l1 || l2 || forward) {
            int tmp_sum = 0;
            if (l1) {
                tmp_sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                tmp_sum += l2->val;
                l2 = l2->next;
            }
            ListNode* tmp = new ListNode((tmp_sum + forward) % 10);
            forward = (tmp_sum + forward) / 10;
            tail->next = tmp;
            tail = tail->next;
        }

        return res->next;
    }
};