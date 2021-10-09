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
    ListNode* FindKthToTail(ListNode* head, unsigned int k) {
        // 暴力法
//         int len = 0;
//         ListNode* p = head;
//         while (p != nullptr) {
//             p = p->next;
//             len ++;
//         }
//         len -= k;
//         if (len < 0) return nullptr;
//         while (len > 0) {
//             len--;
//             head = head->next;
//         } 
//         return head;
        
        // 快慢指针
        ListNode* fast = head;
        ListNode* slow = head;
        while (k > 0) {
            k--;
            if (fast != nullptr) fast = fast->next;
            else return nullptr;
        }
        
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};