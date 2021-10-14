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
<<<<<<< HEAD
    
    int NumberOf1Between1AndN_Solution(int n) {
=======
    int NumberOf1Between1AndN_Solution(int n) {
        // 暴力方法
>>>>>>> 1b52e793c5f93c628989990f36a3b706aa831259
//         int res = 0;
//         for (int i = 1; i <= n; i ++ ) {
//             res += getOne(i);
//         }
//         return res;
<<<<<<< HEAD
        
        int high = n / 10, cur = n % 10, low = 0;
        int digit = 1;
        int cnt = 0;
=======
        int cnt = 0;
        int high = n / 10, cur = n % 10, low = 0;
        int digit = 1;
>>>>>>> 1b52e793c5f93c628989990f36a3b706aa831259
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