#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    class cmp {
    public: // 小顶堆
        bool operator()(const pair<int, int> &l, const pair<int, int> &r) {
            return l.second > r.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i ++ ) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto it = mp.begin(); it != mp.end(); it ++ ) {
            q.push(*it);
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<int> res(k);
        for (int i = k - 1; i >= 0; i -- ) {
            res[i] = q.top().first;
            q.pop();
        }
        
        return res;
    }
};


// //升序队列，小顶堆
// priority_queue <int,vector<int>,greater<int> > q;
// //降序队列，大顶堆
// priority_queue <int,vector<int>,less<int> >q;