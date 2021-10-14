#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n, 0);
        res[0] = 1;
        int i = 0, j = 0, k = 0; // i, j, k分别表示没有乘过2, 3, 5的丑数下标
        for (int idx = 1; idx < n; idx ++ ) {
            int t = min(min(res[i] * 2, res[j] * 3), res[k] * 5);
            if (t == res[i] * 2) i++;
            if (t == res[j] * 3) j++;
            if (t == res[k] * 5) k++;
            res[idx] = t; 
        }
        return res[n - 1];
    }
};