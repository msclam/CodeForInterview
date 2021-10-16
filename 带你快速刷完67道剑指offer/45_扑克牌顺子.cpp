#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool IsContinuous(vector<int> A) {
        sort(A.begin(), A.end());
        int n = A.size();
        int cnt = 0;
        for (int i = 0; i < n; i ++ ) {
            if (A[i] == 0) {
                cnt++;
            } else if (i > 0 && A[i] == A[i - 1]) {
                return false;
            }
        }
        return A[4] - A[cnt] <= 4;
    }
};