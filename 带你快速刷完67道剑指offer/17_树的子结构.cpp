#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (A == nullptr || B == nullptr)
            return false;

        return isSubStructure(A->left, B) || isSubStructure(A->right, B) || isContain(A, B);
    }
    bool isContain(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr)
            return true;
        if (A == nullptr)
            return false;
        if (A->val != B->val)
            return false;

        return isContain(A->left, B->left) && isContain(A->right, B->right);
    }
};