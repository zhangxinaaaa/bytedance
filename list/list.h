//
// Created by 张新 on 2022/9/3.
//

#ifndef BYTEDANCE_LIST_H
#define BYTEDANCE_LIST_H
#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode* next = nullptr;
    ListNode() { val = 0;}
    ListNode(int x): val(x) {}
};


// 翻转
ListNode* reverseListKGroup(ListNode* head, int k);

// 删除
ListNode* deleteDuplicates(ListNode* head);

// 排序

// 合并

// 判断是否有环

ListNode* genList(std::vector<int>& nums) {
    ListNode dummy;
    auto tail = &dummy;
    for (int num : nums) {
        auto node = new ListNode(num);
        tail->next = node;
        tail = tail->next;
    }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}



#endif //BYTEDANCE_LIST_H
