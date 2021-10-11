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
    vector<vector<int> > FindPath(TreeNode* root,int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        if (root == nullptr) return res;
        dfs(root, sum, res, tmp);
        return res;
    }
    void dfs(TreeNode* root,int sum, vector<vector<int>> &res, vector<int> &tmp) {
        if (root == nullptr) return;
        
        tmp.push_back(root->val);
        
        if (sum == root->val && root->left == nullptr && root->right == nullptr) res.push_back(tmp);
        if (root->left) dfs(root->left, sum - root->val, res, tmp);
        if (root->right) dfs(root->right, sum - root->val, res, tmp);
        
        tmp.pop_back();
    }
};