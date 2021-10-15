#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int target) {
//         vector<vector<int>> res;
//         for (int i = 1; i <= sum; i ++ ) {
//             int s = 0; 
//             for (int j = i; j < sum; j ++ ) {
//                 s += j;
//                 if (s == sum) {
//                     vector<int> tmp;
//                     for (int k = i; k <= j; k ++ ) {
//                         tmp.push_back(k);
//                     }
//                     res.push_back(tmp);               
//                 } else if (s > sum) {
//                     break;
//                 }
//             }
//         }
//         return res;
        
        int l = 1, r = 1;
        int sum = 0;
        vector<vector<int>> res;
        while (l <= target / 2) {
            if (sum < target) {
                sum += r;
                r++;
            } else if (sum > target) {
                sum -= l;
                ++l;
            } else {
                vector<int> tmp;
                for (int i = l; i < r; i ++ ) {
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                sum -= l;
                ++l;
            }
        }
        return res;
    }
};