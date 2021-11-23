#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        // if (root == nullptr) return 0;
        // int depth = 0;
        // for (Node* node : root->children) {
        //     depth = max(depth, maxDepth(node));
        // }
        // return depth + 1;

        if (root == nullptr) return 0;

        int depth = 0;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            depth++;
            for (int i = 0; i < n; i ++ ) {
                Node* node = q.front();
                q.pop();
                for (int i = 0; i < node->children.size(); i ++ ) {
                    if (node->children[i]) {
                        q.push(node->children[i]);
                    }
                }
            }
        }
        return depth;
    }
};