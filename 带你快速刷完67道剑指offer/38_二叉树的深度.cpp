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
    int TreeDepth(TreeNode* root) {
        // 递归
//         if (root == nullptr) return 0;
//         return max(TreeDepth(root->left), TreeDepth(root->right)) + 1;
        
        // 迭代
        if (root == nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        int maxDep = 1;
        q.push({root, 1});
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int curDep = q.front().second;
            q.pop();
            maxDep = max(maxDep, curDep);
            if (node->left) q.push({node->left, curDep + 1});
            if (node->right) q.push({node->right, curDep + 1});
        }
        return maxDep;
        
//         if (root == nullptr) return 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         int depth = 0;
//         while (!q.empty()) {
//             int n = q.size();
//             for (int i = 0; i < n; i ++ ) {
//                 TreeNode* node = q.front();
//                 q.pop();
//                 if (node->left) q.push(node->left);
//                 if (node->right) q.push(node->right);
//             }
//             depth++;
//         }
//         return depth;
    }
};