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
    TreeNode* Convert(TreeNode* root) {
        if (root == nullptr) return nullptr;
        vector<TreeNode*> res;
        inOrder(root, res);
        return modif(res);
    }
    
    void inOrder(TreeNode* root, vector<TreeNode*> &res) {
        if (root == nullptr) return;
        if (root->left) inOrder(root->left, res);
        res.push_back(root);
        if (root->right) inOrder(root->right, res);
    }
    
    TreeNode* modif(vector<TreeNode*> &res) {
        int n = res.size();
        for (int i = 0; i < n - 1; i ++ ) {
            res[i]->right = res[i + 1];
            res[i + 1]->left = res[i];
        }
        return res[0];
    }
};