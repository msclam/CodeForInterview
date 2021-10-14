#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& A, int k) {
        // 方式一
        // int n = A.size();
        // vector<int> res;
        // if (k == 0 || n == 0 || k > n) return res;

        // priority_queue<int, vector<int>, greater<int>> q; // 小顶堆
        // for (auto i : A) {
        //     q.push(i);
        // }

        // while (k--) {
        //     res.push_back(q.top());
        //     q.pop();
        // }
        // return res;

        int n = A.size();
        if (k == 0 || n == 0 || k > n) return vector<int>();
        return getKnum(A, k, 0, n - 1);
    }

    int partition(vector<int> &A, int l, int r) {
        int x = A[l];
        while (l < r) {
            while (l < r && A[r] > x) r--;
            A[l] = A[r];
            while (l < r && A[l] <= x) l++;
            A[r] = A[l]; 
        }
        A[l] = x;
        return l;
    }

    vector<int> getKnum(vector<int> &A, int k, int l, int r) {
        int i = partition(A, l, r);
        vector<int> res;
        if (i == k - 1) {
            res.assign(A.begin(), A.begin() + k);
            return res;
        }
        return i > k - 1 ? getKnum(A, k, l, i - 1) : getKnum(A, k, i + 1, r);
    }
};