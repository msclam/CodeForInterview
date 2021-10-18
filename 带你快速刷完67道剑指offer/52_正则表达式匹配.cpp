#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string A, string B) {
        int m = A.size(), n = B.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        for (int i = 0; i <= m; i ++ ) {
            for (int j = 0; j <= n; j ++ ) {
                if (i == 0 && j == 0) {
                    f[i][j] = true;
                    continue;
                }
                if (j == 0) {
                    f[i][j] = false;
                    continue;
                }
                f[i][j] = false;
                if (B[j - 1] != '*') {
                    if (i >= 1 && (B[j - 1] == '.' || B[j - 1] == A[i - 1])) {
                        f[i][j] = f[i][j] || f[i - 1][j - 1];
                    }
                } else {
                    if (j >= 2) {
                        f[i][j] = f[i][j] || f[i][j - 2];
                    }
                    if (j >= 2 && i >= 1 && (B[j - 2] == '.' || B[j - 2] == A[i - 1])) {
                        f[i][j] = f[i][j] || f[i - 1][j];
                    }
                }
            }
        }
        return f[m][n];
    }
};