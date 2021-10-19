#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode* head = new ListNode(INT_MAX);
        ListNode* p = head;
        // 不保留重复的元素
        while (pHead != nullptr) { 
            if (pHead->next == nullptr || pHead->val != pHead->next->val) {
                p->next = pHead;
                p = p->next;
            } 
            while (pHead->next != nullptr && pHead->val == pHead->next->val) {
                pHead = pHead->next;
            }
            pHead = pHead->next;
        }
        
        // 保留重复的元素
//         while (pHead != nullptr) {
//             if (p->val != pHead->val) {
//                 p->next = pHead;
//                 p = p->next;
//             }
//             pHead = pHead->next;
//         } 
            
        p->next = nullptr;
        
        return head->next;
    }
};