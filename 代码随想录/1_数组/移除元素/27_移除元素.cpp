#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        int n = nums.size();
        for (int i = 0; i < n; i ++ ) {
            if (val != nums[i]) {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};