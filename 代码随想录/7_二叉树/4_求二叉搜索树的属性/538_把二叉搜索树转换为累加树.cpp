#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
};

class Solution {
public:
    int pre;
    TreeNode* convertBST(TreeNode* root) {
        // pre = 0;
        // inTraversal(root);
        // return root;

        pre = 0;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur != nullptr) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->right;
            } else {
                cur = st.top();
                st.pop();
                cur->val += pre;
                pre = cur->val;
                cur = cur->left;
            }
        }
        return root;
    }
    void inTraversal(TreeNode* root) {
        if (root == nullptr) return;

        inTraversal(root->right);

        root->val += pre;
        pre = root->val;

        inTraversal(root->left);
    }
};