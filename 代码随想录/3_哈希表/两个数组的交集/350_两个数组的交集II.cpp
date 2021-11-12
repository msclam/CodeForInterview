#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int i : nums1) {
            mp[i]++;
        }

        vector<int> res;
        for (int i : nums2) {
            if (mp.count(i)) {
                res.push_back(i);
                mp[i]--;
                if (mp[i] == 0) {
                    mp.erase(i);
                }
            }
        }
        return res;
    }
};