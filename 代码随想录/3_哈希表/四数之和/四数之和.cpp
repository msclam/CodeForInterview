#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int k = 0; k < n; k ++ ) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            for (int i = k + 1; i < n; i ++ ) {
                if (i > k + 1 && nums[i] == nums[i - 1]) continue;
                int l = i + 1;
                int r = n - 1;
                while (l < r) {
                    if (nums[k] + nums[i] > target - (nums[l] + nums[r])) { // 不这么写四数相加会溢出
                        r--;
                    } else if (nums[k] + nums[i] < target - (nums[l] + nums[r])) {
                        l++;
                    } else {
                        res.push_back(vector<int>{nums[k], nums[i], nums[l], nums[r]});
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        l++;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};