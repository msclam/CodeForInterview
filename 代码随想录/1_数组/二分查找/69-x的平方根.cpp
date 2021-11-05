#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        int l = 0, r = x / 2;
        // mid > sqrt(x) =>  mid^2 > x 注意这样写需要mid为long类型，否则需要写mid > x / mid
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (mid > x / mid) r = mid - 1;
            else l = mid;
        }
        return l;
    } 
};