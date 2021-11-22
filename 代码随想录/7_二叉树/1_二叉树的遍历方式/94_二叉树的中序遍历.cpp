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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 递归
        // vector<int> res;
        // inOrder(root, res);
        // return res;

        // 非递归
        stack<TreeNode*> st;
        vector<int> res;
        if (root == nullptr) return res;
        while (root != nullptr || !st.empty()) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }

    void inOrder(TreeNode* root, vector<int> &res) {
        if (root == nullptr) return;

        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
};