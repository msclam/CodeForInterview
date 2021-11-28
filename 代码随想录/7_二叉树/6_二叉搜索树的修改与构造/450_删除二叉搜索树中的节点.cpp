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
    TreeNode* deleteNode(TreeNode* root, int val) {
        if (root == nullptr) return root;

        if (root->val == val) {
            if (root->left == nullptr && root->right == nullptr) return nullptr;
            else if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            } else if (root->left != nullptr && root->right != nullptr) {
                TreeNode* cur = root->right;
                while (cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left;
                root = root->right;
                return root;
            }
        } else if (root->val > val) {
            root->left = deleteNode(root->left, val);
        } else if (root->val < val) {
            root->right = deleteNode(root->right, val);
        }
        return root;
    }
};