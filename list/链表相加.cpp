//
// Created by 张新 on 2022/9/6.
//
#include "list.h"
using namespace std;

ListNode* sumList(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    ListNode* tail = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        auto node = new ListNode(sum % 10);
        carry = sum / 10;
        tail->next = node;
        tail = tail->next;
    }
    return dummy.next;
}