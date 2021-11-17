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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while (n-- > 0) {
            fast = fast->next;
        } 

        ListNode* pre = nullptr;
        while (fast != nullptr) {
            pre = slow;
            fast = fast->next;
            slow = slow->next;
        }

        pre->next = slow->next;
        slow->next = nullptr;

        return dummyHead->next;
    }
};