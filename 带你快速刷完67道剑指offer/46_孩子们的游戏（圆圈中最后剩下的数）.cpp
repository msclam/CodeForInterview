#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        // 方法一
//         if (n <= 0 || m < 0) return -1;
//         queue<int> q;
//         for (int i = 0; i < n; i ++ ) {
//             q.push(i);
//         }
//         while (q.size() > 1) {
//             for (int i = 0; i < m - 1; i ++ ) {
//                 q.push(q.front());
//                 q.pop();
//             }
//             q.pop();
//         }
//         return q.front();
        
        // 方法二
        if (n <= 0 || m < 0) return -1;
        int res = 0;
        for (int i = 2; i <= n; i ++ ) {
            res = (res + m) % i;
        }
        return res;
    } 
};