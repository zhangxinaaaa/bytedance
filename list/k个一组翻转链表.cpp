//
// Created by 张新 on 2022/9/2.
//
#include "list.h"
// 翻转[head, tail)范围内的数据
ListNode* reverseList(ListNode* head, ListNode* tail) {
    auto cur = head;
    ListNode* pre = nullptr;
    while (cur != tail) {
        auto tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

ListNode* reverseListKGroup(ListNode* head, int k) {
    if(!head)
        return head;
    ListNode *a, *b = head;
    for (int i = 0; i < k; ++i) {
        if(b == nullptr)
            return head;
        b = b->next;
    }// 找到k个节点后的节点
    auto newHead = reverseList(a, b);
    a->next = reverseListKGroup(b, k);
    return newHead;
}