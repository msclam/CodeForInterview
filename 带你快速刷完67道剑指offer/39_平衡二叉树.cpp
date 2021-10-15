#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left, *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* root) {
        if (root == nullptr) return true;
        return IsBalanced_Solution(root->left) && IsBalanced_Solution(root->right) 
            && abs(getDepth(root->left) - getDepth(root->right)) <= 1;
    }
    int getDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
};

