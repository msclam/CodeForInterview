#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int> &A, int n) {
    if (n == 1) return A[0];
    if (A[0] * A[n - 1] >= 0) {
        return A[0] >= 0 ? A[0] : A[n - 1];
    } else {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (A[mid] * A[l] <= 0) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        if (l + 1 < n) {
           return abs(A[l]) < abs(A[l + 1]) ? A[l] : A[l + 1];
        }
        return A[l];
    }
}

int main() {

    vector<int> A = {-2, -1, 2, 3};
    int t = findMin(A, A.size());
    cout << t;
    return 0;
}