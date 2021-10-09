#include <bits/stdc++.h>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        // if (root == nullptr) return nullptr;

        // swap(root->left, root->right);
        // mirrorTree(root->left);
        // mirrorTree(root->right);

        // return root;

        if (root == nullptr) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            swap(node->left, node->right);
        }
        return root;
    }
};