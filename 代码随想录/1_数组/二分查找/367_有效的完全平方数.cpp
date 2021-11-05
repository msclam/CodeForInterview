#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0) return true;
        if (num == 1) return true;
        int l = 1, r = num / 2;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (mid > num / mid) r = mid - 1;
            else l = mid;
        }
        return l * l == num;
    }
};