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
    vector<int> preorderTraversal(TreeNode* root) {
        // 递归
        // vector<int> res;
        // preOrder(root, res);
        // return res;

        // 非递归
        stack<TreeNode*> st;
        vector<int> res;
        if (root == nullptr) return res;
        
        while (!st.empty() || root != nullptr) {
            if (root != nullptr) {
                st.push(root);
                res.push_back(root->val);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                root = root->right;
            }
        }

        return res;
    }

    void preOrder(TreeNode* root, vector<int> &res) {
        if (root == nullptr) return;

        res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }
};