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
    bool isValidBST(TreeNode* root) {
        // 中序迭代
        // stack<TreeNode*> st;
        // TreeNode* pre = nullptr;
        // while (!st.empty() || root != nullptr) {
        //     if (root != nullptr) {
        //         st.push(root);
        //         root = root->left;
        //     } else {
        //         root = st.top();
        //         st.pop();
        //         if (pre != nullptr && pre->val >= root->val) return false;
        //         pre = root;
        //         root = root->right;
        //     }
        // } 
        // return true;

        // 中序递归
        if (root == nullptr) return true;

        bool left = isValidBST(root->left);

        if (pre != nullptr && pre->val >= root->val) return false;
        pre = root;

        bool right = isValidBST(root->right);
        return left && right;
    }
};