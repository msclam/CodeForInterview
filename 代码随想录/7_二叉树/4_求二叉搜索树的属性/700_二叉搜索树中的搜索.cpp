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
    TreeNode* searchBST(TreeNode* root, int val) {
        // 递归
        // if (root == nullptr) return nullptr;
        // if (root->val == val) return root;
        // else if (root->val < val) return searchBST(root->right, val);
        // else if (root->val > val) return searchBST(root->left, val);

        // return nullptr;

        // 迭代
        while (root != nullptr) {
            if (root->val == val) return root;
            else if (root->val < val) root = root->right;
            else root = root->left;
        }
        return nullptr;
    }
};