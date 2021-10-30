#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 方法1 暴力法
        // int n = nums.size();
        // vector<int> res;
        // for (int i = 0; i < n; i ++ ) {
        //     for (int j = i + 1; j < n; j ++ ) {
        //         if (nums[i] + nums[j] == target) {
        //             res.push_back(i);
        //             res.push_back(j);
        //             break;
        //         }
        //     }
        // }
        // return res;

        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> res;        
        for (int i = 0; i < n; i ++ ) {
            int gap = target - nums[i];
            if (mp.find(gap) != mp.end() && mp[gap] != i) {
                res.push_back(i);
                res.push_back(mp[gap]);
                break;
            }
            mp[nums[i]] = i;
        }
        return res;

    }
};