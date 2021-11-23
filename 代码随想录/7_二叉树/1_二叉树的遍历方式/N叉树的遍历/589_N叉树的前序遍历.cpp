#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == nullptr) return res;
        pre(root, res);
        return res;
    }

    void pre(Node* root, vector<int> &res) {
        if (root == nullptr) return;
        res.push_back(root->val);
        int n = root->children.size();
        for (int i = 0; i < n; i ++ ) {
            if (root->children[i]) {
                pre(root->children[i], res);
            }
        }
    }
};