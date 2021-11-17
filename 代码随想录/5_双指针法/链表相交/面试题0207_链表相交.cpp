#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val):val(val), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 求出差值，然后让长的链表移动差值直到A和B同步
        ListNode* curA = headA;
        ListNode* curB = headB;

        int lenA = 0;
        int lenB = 0;

        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }

        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }

        curA = headA;
        curB = headB;

        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        int gap = lenA - lenB;
        while (gap-- > 0) {
            curA = curA->next;
        }

        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};