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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> res;
        if (root == nullptr) return res;
        path.push_back(root->val);
        dfs(root, targetSum - root->val, path, res);
        return res;
    }

    void dfs(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &res) {
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            res.push_back(path);
            return;
        } 
        if (root->left == nullptr && root->right == nullptr) return;

        if (root->left) {
            path.push_back(root->left->val);
            sum -= root->left->val;
            dfs(root->left, sum, path, res);
            sum += root->left->val;
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->right->val);
            sum -= root->right->val;
            dfs(root->right, sum, path, res);
            sum += root->right->val;
            path.pop_back();
        }
    }
};