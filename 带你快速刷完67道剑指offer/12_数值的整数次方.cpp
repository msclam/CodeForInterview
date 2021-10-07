#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double Power(double a, int b) {
        // 方式一
//         if (b < 0) {
//             b = -b;
//             a = 1 / a;
//         }
//         double res = 1.0;
//         for (int i = 1; i <= b; i ++ ) {
//             res *= a;
//         }
//         return res;
        
        /* 方式二：快速幂
            X^n   *   res
        0   3^5       1
        1   9^2       1*3
        2   81^1      1*3*9
        3   (81^2)^0  1*3*9*81 
        */
        if (b < 0) {
            b = -b;
            a = 1 / a;
        }
        double res = 1.0;
        while (b) {
            if (b & 1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
};