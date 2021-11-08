#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<int> res(m * n, 0);

        int t = 0, b = m - 1;
        int l = 0, r = n - 1;
        int idx = 0;

        while (true) {
            for (int i = l; i <= r; i ++ ) res[idx++] = A[t][i];
            if (++t > b) break;

            for (int i = t; i <= b; i ++ ) res[idx++] = A[i][r];
            if (--r < l) break;

            for (int i = r; i >= l; i -- ) res[idx++] = A[b][i];
            if (--b < t) break;

            for (int i = b; i >= t; i -- ) res[idx++] = A[i][l];
            if (++l > r) break;
        }

        return res;
    }
};