//
// Created by 张新 on 2022/9/11.
//
#include "tree.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// 用两个指针，一块一慢，快的每次走两步，慢的每次走一步，这样当快指针遍历结束时，
// 慢指针指向的也就是链表的中间位置。这时候把中间位置的结点的值作为二叉搜索树当前结点的值
TreeNode* sortedListToBST(ListNode* head) {
    if (!head)
        return nullptr;
    if (!head->next)
        return new TreeNode(head->val);
    ListNode *slow = head, *fast = head, *pre = nullptr;
    while (fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;
    TreeNode *root = new TreeNode(slow->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
}

