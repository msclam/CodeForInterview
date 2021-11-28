#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n) {
        // if (n <= 1) return n;
        // vector<int> f(n + 1);
        // f[1] = 1;
        // f[2] = 2;
        // for (int i = 3; i <= n; i ++ ) {
        //     f[i] = f[i - 1] + f[i - 2];
        // }
        // return f[n];
        
        if (n <= 1) return n;
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= 2; j ++ ) {
                if (i - j >= 0) f[i] += f[i - j];
            } 
        }
        return f[n];
    }