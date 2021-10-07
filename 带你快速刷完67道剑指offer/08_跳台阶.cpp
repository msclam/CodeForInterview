#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        // if (n == 0 || n == 1) return 1;
        // if (n == 2) return 2;
        // return numWays(n - 1) + numWays(n - 2);
        if (n == 0 || n == 1) return 1;
        vector<int> f(n + 1, 0);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i ++ ) {
            f[i] = (f[i - 1] + f[i - 2]) %  1000000007;
        }
        return f[n];
    }
};