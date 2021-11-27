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
    void dfs(TreeNode* root, unordered_map<int, int>& mp) {
        if (root == nullptr) return;

        dfs(root->left, mp);
        mp[root->val]++;
        dfs(root->right, mp);
    }

    bool static cmp(const pair<int, int> &A, const pair<int, int> &B) {
        return A.second > B.second;
    }

    vector<int> findMode(TreeNode* root) {
        // unordered_map<int, int> mp;
        // vector<int> res;
        // if (root == nullptr) return res;

        // dfs(root, mp);

        // vector<pair<int, int>> vec(mp.begin(), mp.end());
        // sort(vec.begin(), vec.end(), cmp);

        // res.push_back(vec[0].first);
        // for (int i = 1; i < vec.size(); i ++ ) {
        //     if (vec[i].second == vec[0].second) {
        //         res.push_back(vec[i].first);
        //     } else {
        //         break;
        //     }
        // }      
        // return res;

        vector<int> res;
        if (root == nullptr) return res;

        int maxCnt = 0;
        int cnt = 0;
        check(root, maxCnt, cnt, res);

        return res;
    }
    TreeNode* pre = nullptr;
    void check(TreeNode* root, int &maxCnt, int &cnt, vector<int> &res) {
        if (root == nullptr) return;

        check(root->left, maxCnt, cnt, res);

        if (pre == nullptr) {
            cnt = 1;
        } else if (pre->val == root->val) {
            cnt++;
        } else {
            cnt = 1;
        }
        pre = root;

        if (cnt == maxCnt) res.push_back(root->val);

        if (cnt > maxCnt) {
            maxCnt = cnt;
            res.clear();
            res.push_back(root->val);
        }

        check(root->right, maxCnt, cnt, res);
    }
};