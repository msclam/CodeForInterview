#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> A,int sum) {
        int n = A.size();
        int i = 0, j = n - 1;
        while (i < j) {
            int res = A[i] + A[j];
            if (res == sum) {
                return vector<int>{A[i], A[j]};
            } else if (res > sum) {
                j--;
            } else {
                i++;
            }
        }
        return vector<int>{};
    }
};