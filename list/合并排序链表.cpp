//
// Created by 张新 on 2022/9/12.
//
#include "list.h"
using namespace std;

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty())
        return nullptr;
    if (lists.size() == 1)
        return lists[0];
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    while (true) {
        int min = INT_MAX;
        int index = -1;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] && lists[i]->val < min) {
                min = lists[i]->val;
                index = i;
            }
        }
        if (index == -1)
            break;
        p->next = lists[index];
        p = p->next;
        lists[index] = lists[index]->next;
    }
    return head->next;
}