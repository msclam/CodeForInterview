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
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        for (int i = 0; i < n; i ++ ) {
            mp[in[i]] = i;
        }
        return create(pre, in, 0, n - 1, 0, n - 1);
    }
    TreeNode* create(vector<int>& pre, vector<int>& in, int preL, int preR, int inL, int inR) {
        if (pre.size() != in.size() || preL > preR || inL > inR) return nullptr;
        
        int root = pre[preL];
        // int k;
        // for (k = inL; k <= inR; k ++ ) {
        //     if (root == in[k]) {
        //         break;
        //     }
        // }
        int k = mp[root];
        int numL = k - inL;

        TreeNode* node = new TreeNode(root);
        node->left = create(pre, in, preL + 1, preL + numL, inL, k - 1);
        node->right = create(pre, in, preL + numL + 1, preR, k + 1, inR);
        
        return node; 
    }
};