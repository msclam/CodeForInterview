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
    int countNodes(TreeNode* root) {
        // 递归
        // if (root == nullptr) return 0;

        // int leftNodes = countNodes(root->left);
        // int rightNodes = countNodes(root->right);
        // int res = leftNodes + rightNodes + 1;

        // return res;

        // 迭代
        // if (root == nullptr) return 0;
        // queue<TreeNode*> q;
        // q.push(root);
        // int res = 0;
        // while (!q.empty()) {
        //     int n = q.size();
        //     for (int i = 0; i < n; i ++ ) {
        //         res++;
        //         TreeNode* node = q.front();
        //         q.pop();
        //         if (node->left) q.push(node->left);
        //         if (node->right) q.push(node->right);
        //     }
        // }
        // return res;

        if (root == nullptr) return 0;
        
        int left = 0, right = 0;
        TreeNode* l = root->left;
        TreeNode* r = root->right;

        while (l != nullptr) {
            left++;
            l = l->left;
        }

        while (r != nullptr) {
            right++;
            r = r->right;
        }

        if (left == right) return (2<<left) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};