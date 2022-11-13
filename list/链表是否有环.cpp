//
// Created by 张新 on 2022/9/3.
//
#include <vector>
/*
可以使用快慢指针法， 分别定义 fast 和 slow指针，从头结点出发，fast指针每次移动两个节点，slow指针每次移动一个节点，如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。

为什么fast 走两个节点，slow走一个节点，有环的话，一定会在环内相遇呢，而不是永远的错开呢？

首先第一点： fast指针一定先进入环中，如果fast 指针和slow指针相遇的话，一定是在环中相遇，这是毋庸置疑的。

那么来看一下，为什么fast指针和slow指针一定会相遇呢？

可以画一个环，然后让 fast指针在任意一个节点开始追赶slow指针。

会发现最终都是这种情况

 fast和slow各自再走一步， fast和slow就相遇了

这是因为fast是走两步，slow是走一步，其实相对于slow来说，fast是一个节点一个节点的靠近slow的，所以fast一定可以和slow重合。
 * */

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
};

bool hasCircle(ListNode* head) {
    if (!head || !head->next)
        return false;
    auto fast = head->next->next;
    auto slow = head->next;
    while (fast != slow) {
        if (!fast->next) {
            return false;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    if (!fast || !fast->next)
        return false;
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}