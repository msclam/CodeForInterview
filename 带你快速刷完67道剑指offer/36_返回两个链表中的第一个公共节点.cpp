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
    ListNode* FindFirstCommonNode( ListNode* head1, ListNode* head2) {
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        while (p1 != p2) {
            p1 = p1 != nullptr ? p1->next : head2;
            p2 = p2 != nullptr ? p2->next : head1;
        }
        return p1;
    }
};