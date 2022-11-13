//
// Created by 张新 on 2022/9/4.
//
#include "list.h"

// 给定单链表的头节点head，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。
//
//第一个节点的索引被认为是 奇数 ， 第二个节点的索引为偶数 ，以此类推。

//输入: head = [1,2,3,4,5]
//输出: [1,3,5,2,4]



class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto ou = new ListNode(), ji = new ListNode();
        auto tj = ji, to = ou;
        int i=1;
        while (head) {
            if (i % 2) {
                tj->next = head;
                tj = tj->next;
            } else {
                to->next = head;
                to = to->next;
            }
            head = head->next;
            i++;
        }
        to->next = nullptr;
        tj->next = ou->next;
        return ji->next;
    }
};
