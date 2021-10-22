#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    int X[4] = {0, 0, 1, -1};
    int Y[4] = {1, -1, 0, 0};
    vector<vector<bool>> st;
    bool hasPath(vector<vector<char> >& A, string s) {
        int m = A.size(), n = A[0].size();
        st.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (dfs(A, i, j, s, 0, m, n)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char> >& A, int x, int y, string s, int idx, int m, int n) {
        if (idx == s.size()) return true;
        if (x < 0 || x >= m || y < 0 || y >= n) return false;
        if (st[x][y] || A[x][y] != s[idx]) return false;
        bool flag = false;
        st[x][y] = true;
        for (int i = 0; i < 4; i ++ ) {
            int nx = X[i] + x;
            int ny = Y[i] + y;
            flag = flag || dfs(A, nx, ny, s, idx + 1, m, n);
        }
        st[x][y] = false;
        
        return flag;
    }
};