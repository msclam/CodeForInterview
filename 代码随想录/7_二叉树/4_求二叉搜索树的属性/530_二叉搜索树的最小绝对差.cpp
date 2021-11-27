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
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        // int res = INT_MAX;
        // dfs(root, res);
        // return res;

        stack<TreeNode*> st;
        TreeNode* pre = nullptr;
        int res = INT_MAX;
        while (!st.empty() || root != nullptr) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                if (pre != nullptr) {
                    res = min(res, root->val - pre->val);
                }
                pre = root;
                root = root->right;
            }
        }
        return res;
    }
    void dfs(TreeNode* root, int &res) {
        if (root == nullptr) return;

        dfs(root->left, res);

        if (pre != nullptr) {
            res = min(res, root->val - pre->val);
        }
        pre = root;

        dfs(root->right, res);
    }
};