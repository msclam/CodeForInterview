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
    ListNode* reverseList(ListNode* head) {
        // 迭代法
        // if (head == nullptr || head->next == nullptr) return head;

        // ListNode* pre = nullptr;
        // ListNode* cur = head;
        // while (cur != nullptr) {
        //     ListNode* tmp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = tmp;
        // }

        // return pre;

        // 递归
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* nhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return nhead;
    }
};