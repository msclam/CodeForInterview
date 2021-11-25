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
    int minDepth(TreeNode* root) {
        // 递归
        // if (root == nullptr) return 0;

        // int left = minDepth(root->left);
        // int right = minDepth(root->right);

        // if (root->left == nullptr && root->right != nullptr) {
        //     return right + 1;
        // }
        // if (root->left != nullptr && root->right == nullptr) {
        //     return left + 1;
        // }

        // return 1 + min(left, right);

        // 迭代
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int n = q.size();
            depth++;
            for (int i = 0; i < n; i ++ ) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (node->left == nullptr && node->right == nullptr) {
                    return depth; 
                }
            }
        }
        return depth;
    }
};