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
        // 方法三
        if (root == nullptr) return nullptr;
        TreeNode* head = nullptr, *pre = nullptr; 
        stack<TreeNode*> st;
        while (!st.empty() || root != nullptr) {
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }
            if (!st.empty()) {
                root = st.top();
                st.pop();
                if (pre != nullptr) {
                    pre->right = root;
                    root->left = pre;
                } else {
                    head = root;
                }
                pre = root;
                root = root->right;
            }
        }
        return head;
    }
    
    TreeNode* Convert(TreeNode* root) {
        if (root == nullptr) return nullptr;
        vector<TreeNode*> res;
        // 方法一递归+vector
//         inOrder(root, res);
        // 方法二非递归+vector
        NotinOrder(root, res);
        
        int n = res.size();
        for (int i = 0; i < n - 1; i ++ ) {
            res[i]->right = res[i + 1];
            res[i + 1]->left = res[i];
        }
        
        return res[0];
    }
    
    void inOrder(TreeNode* root, vector<TreeNode*>& res) {
        if (root == nullptr) return ;
        inOrder(root->left, res);
        res.push_back(root);
        inOrder(root->right, res);
    }
    
    void NotinOrder(TreeNode* root, vector<TreeNode*>& res) {
        if (root == nullptr) return;
        stack<TreeNode*> st;
        while (!st.empty() || root != nullptr) {
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }
            if (!st.empty()) {
                root = st.top();
                st.pop();
                res.push_back(root);
                root = root->right;
            }
        }
    }
};
    
