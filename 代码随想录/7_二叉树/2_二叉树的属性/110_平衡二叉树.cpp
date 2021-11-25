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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        return abs(getHeight(root->left) - getHeight(root->right)) <= 1 && 
            isBalanced(root->left) && isBalanced(root->right);
    }

    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int res = max(left, right) + 1;
        return res;
    }
};