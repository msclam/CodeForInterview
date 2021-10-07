#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rectCover(int n) {
        // f[n]表示n个矩形的覆盖方式, 最后一个竖着一块 f[n - 1] 最后是横着两块f[n - 2]
        if (n == 0) return 0;
        vector<int> f(n + 1, 0);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i ++ ) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};