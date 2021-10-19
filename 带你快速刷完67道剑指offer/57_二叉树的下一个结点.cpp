#include <bits/stdc++.h>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    void inOrder(TreeLinkNode* root, vector<TreeLinkNode*> &v) {
        if (root == NULL) {
            return;
        }
        inOrder(root->left, v);
        v.push_back(root);
        inOrder(root->right, v);
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
//         if (pNode == NULL) return NULL;
        
//         TreeLinkNode* root = NULL;
//         TreeLinkNode* tmp = pNode;
        
//         // 找到根节点
//         while (tmp != NULL) {
//             root = tmp;
//             tmp = tmp->next;
//         }
        
//         vector<TreeLinkNode*> v;
//         inOrder(root, v);
        
//         int n = v.size();
//         for (int i = 0; i < n; i ++ ) {
//             if (v[i] == pNode && i + 1 < n) {
//                 return v[i + 1];
//             }
//         }
//         return NULL;
        
        if (pNode == NULL) return NULL;
        
        if (pNode->right != NULL) {
            pNode = pNode->right;
            while (pNode->left != NULL) {
                pNode = pNode->left;
            }
            return pNode;
        }
        
        while (pNode->next != NULL) {
            if (pNode->next->left == pNode) {
                return pNode->next;
            }
            pNode = pNode->next;
        }
        return NULL;
    }
};