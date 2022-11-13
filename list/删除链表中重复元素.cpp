//
// Created by 张新 on 2022/9/4.
//
#include "list.h"
using  namespace std;


// [1, 2, 2, 3, 4] -> [1, 2, 3, 4]
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode dummy;
        auto tail = &dummy;
        tail->next = head;
        tail = tail->next;
        while (head) {
            while (head && head->val == tail->val)
                head = head->next;
            tail->next = head;
            tail = tail->next;
            head = head->next;
        }
        tail->next = nullptr; // 从已经构建好的链表中拿元素，一定要把尾指针置空
        return dummy.next;
    }
};

// [1, 2, 2, 3, 4] -> [1, 3, 4]

class Sol {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1),tail = dummy;
        while(head){
            if(head->next == nullptr or head->val != head->next->val){
                tail->next = head;
                tail = head;
            }
            while(head->next and head->val == head->next->val)
                head = head->next;
            head = head->next;
        }
        tail->next = nullptr;
        return dummy->next;
    }
};