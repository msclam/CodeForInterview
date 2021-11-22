#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    class MyQueue {
    public:
        // 实现单调队列
        deque<int> q;
        void pop(int val) {
            if (!q.empty() && q.front() == val) {
                q.pop_front();
            }
        }

        void push(int val) {
            while (!q.empty() && val > q.back()) {
                q.pop_back();
            }
            q.push_back(val);
        }

        int front() {
            return q.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue q;
        vector<int> res;
        for (int i = 0; i < k; i ++ ) {
            q.push(nums[i]);
        }
        res.push_back(q.front());

        for (int i = k; i < nums.size(); i ++ ) {
            q.pop(nums[i - k]);
            q.push(nums[i]);
            res.push_back(q.front());
        }

        return res;
    }
};