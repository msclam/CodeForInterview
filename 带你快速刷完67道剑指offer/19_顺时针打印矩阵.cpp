#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        vector<int> res;
        if (A.size() == 0 || A[0].size() == 0) return res;
        int m = A.size(), n = A[0].size();
        int t = 0, b = m - 1;
        int l = 0, r = n - 1;
        while (true) {
            for (int i = l; i <= r; i ++ ) res.push_back(A[t][i]);
            if (++t > b) break;

            for (int i = t; i <= b; i ++ ) res.push_back(A[i][r]);
            if (--r < l) break;

            for (int i = r; i >= l; i -- ) res.push_back(A[b][i]);
            if (--b < t) break;

            for (int i = b; i >= t; i -- ) res.push_back(A[i][l]);
            if (++l > r) break; 
        }
        return res;
    }
};