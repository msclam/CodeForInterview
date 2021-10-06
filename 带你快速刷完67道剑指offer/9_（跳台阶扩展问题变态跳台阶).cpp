#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jumpFloorII(int n) {
        //f[n] = f[n - 1] + f[n - 2] + ... f[0]
//         if (n == 0 || n == 1) return 1;
//         vector<int> f(n + 1, 0);
//         f[0] = f[1] = 1;
//         for (int i = 2; i <= n; i ++ ) {
//             for (int j = 0; j < i; j ++ ) {
//                 f[i] += f[j];
//             }
//         }
//         return f[n];
        
        // /f[n] = f[n - 1] + f[n - 2] + ... f[0]
        // f[n - 1] = f[n - 2] + ... + f[0]
//         if (n == 0 || n == 1) return 1;
//         return 2 * jumpFloorII(n - 1);
        
        if (n == 0 || n == 1) return 1;
        return pow(2, n - 1);
    }
};