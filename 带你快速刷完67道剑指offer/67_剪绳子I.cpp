#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
/**
 * leetcode343的整数拆分：给定一个正整数 n，将其拆分为至少两个正整数的和，
 * 并使这些整数的乘积最大化。 返回你可以获得的最大乘积。 
 */
    int cuttingRope(int n) {
        vector<int> f(n + 1, 0);
        if (n < 2) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;

        f[1] = 1;
        f[2] = 2;
        f[3] = 3; // >=4的2和3就不拆
        for (int i = 4; i <= n; i ++ ) {
            for (int j = 1; j <= i / 2; j ++ ) {
                f[i] = max(f[i], f[j] * f[i - j]);
            }
        }
        return f[n];
    }
};

int main() {

    return 0;
}