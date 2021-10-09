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
    ListNode* ReverseList(ListNode* pHead) {
        // 递归
//         if (pHead == nullptr || pHead->next == nullptr) return pHead;
        
//         ListNode* nHead = ReverseList(pHead->next);
//         pHead->next->next = pHead;
//         pHead->next = nullptr;
        
//         return nHead;
        
        // 原地
        ListNode* pre = nullptr;
        ListNode* cur = pHead;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};