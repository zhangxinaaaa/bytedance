
#include "list.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 链表原地排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto slow = head, fast = head->next->next;
        ListNode* left, *right;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        right = mergeSort(slow->next);
        slow->next = nullptr;
        left = mergeSort(head);
        return mergeList(left, right);
    }

    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1);
        auto p = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 == nullptr ? l2 : l1;
        return dummy->next;
    }
};