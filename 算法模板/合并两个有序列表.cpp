#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    ListNode* next;
    int val;
    ListNode(int val):val(val), next(nullptr){}
};

ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;

    while (a != nullptr || b != nullptr) {
        if (a->val <= b->val) {
            cur->next = a;
            cur = cur->next;
            a = a->next;
        } else {
            cur->next = b;
            cur = cur->next;
            b = b->next;
        }
    }
    cur->next = a != nullptr ? a : b;
    return dummyHead->next;
}

int main() {
   
    return 0;
}