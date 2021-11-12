#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i ++ ) {
            mp[nums[i]] = i;
        }
        vector<int> res;
        for (int i = 0; i < n; i ++ ) {
            int gap = target - nums[i];
            if (mp.find(gap) != mp.end() && i != mp[gap]) {
                res.push_back(i);
                res.push_back(mp[gap]);
                break;
            } 
        }
        return res;
    }
};