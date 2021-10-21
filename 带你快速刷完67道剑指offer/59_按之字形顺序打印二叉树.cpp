#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> ans;
            for (int i = 0; i < n; i ++ ) {
                TreeNode* node = q.front();
                q.pop();
                ans.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
            if (level % 2 == 0) {
                reverse(ans.begin(), ans.end());
            }
            res.push_back(ans);
        }
        return res;
    }
    
};