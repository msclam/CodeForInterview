#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<bool>> st;
    int X[4] = {0, 0, 1, -1};
    int Y[4] = {1, -1, 0, 0};
    int getSum(int n) {
        int res = 0;
        while (n != 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    void dfs(int x, int y, int &res, int k, int m, int n) {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (st[x][y] || getSum(x) + getSum(y) > k) return;
        st[x][y] = true;
        res++;
        for (int i = 0; i < 4; i ++ ) {
            int nx = x + X[i];
            int ny = y + Y[i];
            dfs(nx, ny, res, k, m, n);
        }
    }
    int movingCount(int k, int m, int n) {
        st.resize(m, vector<bool>(n, false));
        int res = 0;
        dfs(0, 0, res, k, m, n);
        return res;
    }
};