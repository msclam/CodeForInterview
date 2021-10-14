#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int InversePairs(vector<int> A) {
        int n = A.size();
        vector<int> tmp(n, 0);
        return mergeSort(A, tmp, 0, n - 1);
    } 
    
    int mergeSort(vector<int> &A, vector<int> &tmp, int l, int r) {
        if (l < r) {
            int mid = l + r >> 1;
            int res = (mergeSort(A, tmp, l, mid) + mergeSort(A, tmp, mid + 1, r)) % 1000000007;
            res += merge(A, tmp, l, mid, mid + 1, r) % 1000000007;
            return res;
        } else {
            return 0;
        }
    }
    
    int merge(vector<int> &A, vector<int> &tmp, int l1, int r1, int l2, int r2) {
        int idx = l1;
        int i = l1, j = l2;
        int res = 0;
        while (i <= r1 && j <= r2) {
            if (A[i] <= A[j]) {
                tmp[idx++] = A[i++];
                res += (j - l2) % 1000000007;
            } else {
                tmp[idx++] = A[j++];
            }
        }
        while (i <= r1) {
            tmp[idx++] = A[i++];
            res += (j - l2) % 1000000007;
        }
        while (j <= r2) {
            tmp[idx++] = A[j++];
        }
        
        copy(tmp.begin() + l1, tmp.begin() + r2 + 1, A.begin() + l1);
        
        return res;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& A) {
        int n = A.size();
        vector<int> tmp(n, 0);
        return mergeSort(A, tmp, 0, n - 1);
    }

    int mergeSort(vector<int> &A, vector<int> &tmp, int l, int r) {
        if (l < r) {
            int mid = l + r >> 1;
            int res = mergeSort(A, tmp, l, mid) + mergeSort(A, tmp, mid + 1, r);
            res += merge(A, tmp, l, mid, mid + 1, r);
            return res;
        } else {
            return 0;
        }
    }

    int merge(vector<int> &A, vector<int> &tmp, int l1, int r1, int l2, int r2) {
        int idx = l1;
        int i = l1, j = l2;
        int res = 0;
        while (i <= r1 && j <= r2) {
            if (A[i] <= A[j]) {
                tmp[idx++] = A[i++];
                res += (j - l2);
            } else {
                tmp[idx++] = A[j++];
            }
        }

        while (i <= r1) {
            tmp[idx++] = A[i++];
            res += (j - l2);
        }

        while (j <= r2) {
            tmp[idx++] = A[j++];
        }

        copy(tmp.begin() + l1, tmp.begin() + r2 + 1, A.begin() + l1);

        return res;
    }
};