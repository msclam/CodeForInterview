#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root == nullptr) return root;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            Node* cur = nullptr;
            for (int i = 0; i < n; i ++ ) {
                Node* node = q.front();
                q.pop();
                if (i == 0) {
                    cur = node;
                } else {
                    cur->next = node;
                    cur = cur->next;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right); 
            }
            cur->next = nullptr;
        }
        return root;
    }
};