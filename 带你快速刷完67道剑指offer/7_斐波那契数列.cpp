#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fib(int n) {
        // if (n == 0) return 0;
        // if (n == 1) return 1;
        // return fib(n - 1) + fib(n - 2);
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> f(n + 1, 0);
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= n; i ++ ) {
            f[i] = (f[i - 1] + f[i - 2]) % 1000000007;;
        }
        return f[n];
    }
};