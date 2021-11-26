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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return dfs(root, targetSum - root->val);
    }

    bool dfs(TreeNode* root, int sum) {
        if (root->left == nullptr && root->right == nullptr && sum == 0) return true;
        if (root->left == nullptr && root->right == nullptr) return false;

        if (root->left) {
            sum -= root->left->val;
            if (dfs(root->left, sum)) return true; 
            sum += root->left->val;
        }
        if (root->right) {
            sum -= root->right->val;
            if (dfs(root->right, sum)) return true;
            sum += root->right->val;
        }
        return false;
    }
};