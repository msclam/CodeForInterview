#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        long mod = 1000000007;
        if (n < 4) return n - 1;
        long res = 1;
        while (n > 4) {
            res = (res * 3) % mod;
            n -= 3;
        }
        return (res * n) % mod;
    }
};

int main() {

    return 0;
}