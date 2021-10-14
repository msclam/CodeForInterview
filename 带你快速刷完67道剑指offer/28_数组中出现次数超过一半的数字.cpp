#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> A) {
        // 方法一
//         int n = A.size();
//         int cnt = 0;
//         int res;
//         for (auto i : A) {
//             if (cnt == 0) {
//                 cnt = 1;
//                 res = i;
//             } else {
//                 if (res == i) cnt++;
//                 else cnt--;
//             }
//         }
//         int tmp = count(A.begin(), A.end(), res);
//         return tmp > n / 2 ? res : 0;
        
        // 方法二
        int n = A.size();
        unordered_map<int, int> mp;
        for (auto i : A) {
            mp[i]++;
            if (mp[i] > n / 2) {
                return i;
            }
        }
        return 0;
    }
};