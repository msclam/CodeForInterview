#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> A(n, vector<int>(n, 0));
        int idx = 1;

        int t = 0, b = n - 1;
        int l = 0, r = n - 1;

        while (true) {
            for (int i = l; i <= r; i ++ ) A[t][i] = idx++;
            if (++t > b) break;

            for (int i = t; i <= b; i ++ ) A[i][r] = idx++;
            if (--r < l) break;

            for (int i = r; i >= l; i -- ) A[b][i] = idx++;
            if (--b < t) break;

            for (int i = b; i >= t; i -- ) A[i][l] = idx++;
            if (++l > r) break; 
        }

        return A;
    }
};