#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> A) {
        int n = A.size();
        if (n == 0) return false;
        return check(A, 0, n - 1);
    }
    
    bool check(vector<int> &A, int l, int r) {
        if (l >= r) return true;
        int root = A[r];
        int i = l;
        while (A[i] < root) i++;
        for (int j = i; j < r; j ++ ) {
            if (A[j] < root) {
                return false;
            }
        }
        return check(A, l, i - 1) && check(A, i, r - 1);
    }
};