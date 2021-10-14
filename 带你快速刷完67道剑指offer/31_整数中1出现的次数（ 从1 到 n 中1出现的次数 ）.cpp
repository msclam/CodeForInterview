#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getOne(int n) {
        int cnt = 0;
        while (n != 0) {
            if (n % 10 == 1) cnt ++;
            n /= 10;
        }
        return cnt;
    }
    

    int NumberOf1Between1AndN_Solution(int n) {
        // 暴力方法
//         int res = 0;
//         for (int i = 1; i <= n; i ++ ) {
//             res += getOne(i);
//         }
//         return res;

        
        int high = n / 10, cur = n % 10, low = 0;
        int digit = 1;
        int cnt = 0;
        while (high != 0 || cur != 0) {
            if (cur == 0) {
                cnt += high * digit;
            } else if (cur == 1) {
                cnt += high * digit + low + 1;
            } else {
                cnt += (high + 1) * digit;
            }
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return cnt;
    }
};