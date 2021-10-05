#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        // vector<int> res;
        // if (head == nullptr) return res; 
        // while (head != nullptr) {
        //     res.push_back(head->val);
        //     head = head->next;
        // }
        // reverse(res.begin(), res.end());
        // return res;

        vector<int> res;
        if (head == nullptr) return res;
        res = reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};