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
    TreeNode* invertTree(TreeNode* root) {
        // 递归
        // if (root == nullptr) return root;

        // swap(root->left, root->right);
        // invertTree(root->left);
        // invertTree(root->right);

        // return root;
        
        // 迭代 dfs
        // if (root == nullptr) return root;
        // stack<TreeNode*> st;
        // TreeNode* cur = root;
        // while (!st.empty() || root != nullptr) {
        //     if (root != nullptr) {
        //         st.push(root);
        //         swap(root->left, root->right);
        //         root = root->left;
        //     } else {
        //         root = st.top();
        //         st.pop();
        //         root = root->right;
        //     }
        // }
        // return cur;

        // 迭代bfs
        if (root == nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i ++ ) {
                TreeNode* node = q.front();
                q.pop();
                swap(node->left, node->right);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};