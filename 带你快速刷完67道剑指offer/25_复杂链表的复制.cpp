#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    struct RandomListNode *next, *random;
    Node(int x) :
            val(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    Node* Clone(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node *, Node *> mp;
        
        for (Node* p = head; p != nullptr; p = p->next) {
            mp[p] = new RandomListNode(p->val);
        }
        
        for (Node* p = head; p != nullptr; p = p->next) {
            mp[p]->next = mp[p->next];
            mp[p]->random = mp[p->random];
        }
        
        return mp[head];
    }
};