#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 环形链表的入口位置 2 * (x + y) = x + y + n * (z + y)
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) { // fast == slow 相遇点
                ListNode* cur1 = fast;
                ListNode* cur2 = head;
                while (cur1 != cur2) {
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }
                return cur1;
            }
        }
        return nullptr;
    }
};