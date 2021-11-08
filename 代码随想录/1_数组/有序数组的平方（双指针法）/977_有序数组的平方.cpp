#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int idx = n - 1;
        vector<int> res(n, 0);
        while (i <= j) {
            if (nums[i] * nums[i] <= nums[j] * nums[j]) {
                res[idx--] = nums[j] * nums[j];
                j--;
            } else {
                res[idx--] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }
};