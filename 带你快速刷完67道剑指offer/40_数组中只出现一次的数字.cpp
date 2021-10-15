#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> A,int* a,int *b) {
        int n = A.size();
        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            res ^= A[i];
        }
        int flag = 1;
        while ((flag & res) == 0) {
            flag <<= 1;
        }
        
        *a = 0, *b = 0;
        for (int i = 0; i < n; i ++ ) {
            if (flag & A[i]) *a ^= A[i];
            else *b ^= A[i];
        }
        
//         int n = A.size();
//         unordered_map<int, int> mp;
//         for (int i = 0; i < n; i ++ ) {
//             mp[A[i]]++;
//         }
//         vector<int> res;
//         int cnt = 0;
//         for (int i =0; i < n; i ++ ) {
//             if (mp[A[i]] == 1) {
//                 res.push_back(A[i]);
//                 cnt++;
//                 if (cnt == 2) {
//                     break;
//                 }
//             }
//         }
//         *a = res[0], *b = res[1];
    }
};