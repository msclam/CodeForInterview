#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // if (head == nullptr || head->next == nullptr) return head;

        // ListNode* node = head->next;
        // head->next = swapPairs(node->next);
        // node->next = head;

        // return node;

        if (head == nullptr || head->next == nullptr) return head;

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;

        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next;
            ListNode* tmp1 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tmp;
            tmp->next = tmp1;

            cur = cur->next->next;
        }

        return dummyHead->next;
    }
};