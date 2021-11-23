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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> res;
        if (root == nullptr) return res;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> ans;
            for (int i = 0; i < n; i ++ ) {
                Node* node = q.front();
                q.pop();
                ans.push_back(node->val);
                for (int i = 0; i < node->children.size(); i ++ ) {
                    if (node->children[i]) q.push(node->children[i]);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};