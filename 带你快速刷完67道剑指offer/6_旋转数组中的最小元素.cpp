#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& A) {
        int n = A.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (A[mid] > A[r]) l = mid + 1;
            else if (A[mid] < A[r]) r = mid;
            else {
                r--;
            }
        }
        return A[l];
    }
};