//
// Created by 张新 on 2022/9/3.
//

struct ListNode {
    int val;
    ListNode* next;
};


/*
 *
实现思路 ：以1->2->3->4->5, m = 2, n=4 为例:

定位到要反转部分的头节点 2，head = 2；前驱结点 1，pre = 1；
当前节点的下一个节点3调整为前驱节点的下一个节点 1->3->2->4->5,
当前结点仍为2， 前驱结点依然是1，重复上一步操作。。。
1->4->3->2->5.
 * */
// 翻转(l, r)的元素
ListNode* reverse(ListNode* l, ListNode* r) {
    ListNode* pre = r;
    ListNode* cur = l->next;
    while (cur != r) {
        auto tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur->next = tmp;
    }
    return pre;
}

// 找到翻转区间(a, b)
ListNode* intervalReverse(ListNode* head, int m, int n) {
    ListNode *a = head, *b = head;
    for (int i = 1; i < m - 1; ++i) {
        a = a->next;
    }
    for (int i = 0; i < n; ++i) {
        b = b->next;
    }
    a->next = reverse(a, b);
    return head;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        for(int i = 1; i < m; i++){
            pre = pre->next;
        }
        head = pre->next;
        for(int i = m; i < n; i++){
            ListNode* nex = head->next;
            head->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
        }
        return dummy->next;
    }
};