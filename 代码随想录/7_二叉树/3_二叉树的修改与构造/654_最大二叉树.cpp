#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() {}
    TreeNode(int val):val(val), right(nullptr), left(nullptr) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return bulidTree(nums, 0, nums.size() - 1);
    }

    TreeNode* bulidTree(vector<int> &nums, int l, int r) {
        if (l > r) return nullptr;

        int idx = l;
        for (int i = l; i <= r; i ++ ) {
            if (nums[i] > nums[idx]) {
                idx = i;
            }
        }
        TreeNode* node = new TreeNode(nums[idx]);

        node->left = bulidTree(nums, l, idx - 1);
        node->right = bulidTree(nums, idx + 1, r);

        return node;
    }
};