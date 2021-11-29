#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        
        vector<int> f(n + 1);
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= n; i ++ ) {
            f[i] = f[i - 1] + f[i - 2];
        }

        return f[n];

        // if (n <= 1) return n;

        // vector<int> res(2);
        // res[0] = 0;
        // res[1] = 1;
        // for (int i = 2; i <= n; i ++ ) {
        //     int sum = res[0] + res[1];
        //     res[0] = res[1];
        //     res[1] = sum;
        // }
        // return res[1];
    }
};