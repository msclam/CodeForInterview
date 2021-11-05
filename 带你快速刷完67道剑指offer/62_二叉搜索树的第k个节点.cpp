#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * 注意是第k小还是第k大，如果是第k小，就是左中右，如果是第k大，就是右中左
 */
class Solution {
public:
    int idx = 0;
    int kthLargest(TreeNode* root, int k) {
        TreeNode* t = dfs(root, k);
        if (t != nullptr) return t->val;
        return INT_MAX;    
    }

    TreeNode* inOrder(TreeNode* root, int k) {
        if (root == nullptr) return nullptr;

        TreeNode* t = inOrder(root->right, k);
        if (t != nullptr) return t;

        idx++;
        if (idx == k) return root;

        t = inOrder(root->left, k);
        if (t != nullptr) return t;
        
        return nullptr;
    }

    TreeNode* dfs(TreeNode* root, int k) {
        if (root == nullptr) return nullptr;
        stack<TreeNode*> st;
        while (!st.empty() || root != nullptr) {
            while (root != nullptr) {
                st.push(root);
                root = root->right;
            }
            if (!st.empty()) {
                root = st.top();
                st.pop();
                k--;
                if (k == 0) return root;
                root = root->left;
            }
        }
        return nullptr;
    }
};