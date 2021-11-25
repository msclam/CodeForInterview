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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> res;
        if (root == nullptr) return res;
        dfs(root, path, res);
        return res;
    }

    void dfs(TreeNode* root, vector<int> &path, vector<string> &res) {
        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            string sPath = "";
            int n = path.size();
            for (int i = 0; i < n - 1; i ++ ) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[n - 1]);
            res.push_back(sPath);
            return;
        }

        if (root->left) {
            dfs(root->left, path, res);
            path.pop_back();
        }

        if (root->right) {
            dfs(root->right, path, res);
            path.pop_back();
        }
    }
};