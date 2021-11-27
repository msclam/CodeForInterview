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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if (pre.size() == 0 || in.size() == 0) return nullptr;
        return build(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
    }
    TreeNode* build(vector<int>& pre, vector<int>& in, int preL, int preR, int inL, int inR) {
        if (preL > preR) return nullptr;

        int root = pre[preL];
        TreeNode* node = new TreeNode(root);
        int k;
        for (k = inL; k <= inR; k ++ ) {
            if (in[k] == root) {
                break;
            }
        }
        int numL = k - inL;

        node->left = build(pre, in, preL + 1, preL + numL, inL, k - 1);
        node->right = build(pre, in, preL + numL + 1, preR, k + 1, inR);

        return node;
    }
};