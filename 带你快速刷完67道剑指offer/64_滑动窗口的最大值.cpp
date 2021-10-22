#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        // vector<int> res;
        // int n = A.size();
        // if (k > n || n == 0 || k == 0) return res;
        // int l = 0, r = k - 1;
        // while (r < n) {
        //     int t = INT_MIN;
        //     for (int i = l; i <= r; i ++ ) {
        //         t = max(t, A[i]);
        //     }
        //     res.push_back(t);
        //     l++;
        //     r++;
        // }
        // return res;
        // [1,3,-1,-3,5,3,6,7], 和 k = 3
        // [3, 3, 5, 5, 6, 7]
        
        deque<int> q;
        int n = A.size();
        vector<int> res;
        if (n == 0) return res;
        for (int i = 0; i < n; i ++ ) {
            while (!q.empty() && i - q.front() + 1 > k) {
                q.pop_front();
            }
            while (!q.empty() && A[i] >= A[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                res.push_back(A[q.front()]);
            }
        }
        return res;
    }
};