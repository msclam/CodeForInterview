#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> A ,int k) {
        int n = A.size();
        if (n == 0) return 0;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (A[mid] < k) l = mid + 1;
            else r = mid;
        }
        if (A[l] != k) return 0;
        else {
            int tmp = l;
            l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (A[mid] > k) r = mid - 1;
                else l = mid;
            }
            if (A[l] != k) {
                return 1;
            } else {
                return r - tmp + 1;
            }
        }
    }
};