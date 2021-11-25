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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);

        int value = 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            value = root->left->val;
        }
        int sum = left + right + value;

        return sum;
    }
};