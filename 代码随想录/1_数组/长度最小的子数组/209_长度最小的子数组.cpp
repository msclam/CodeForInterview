#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int sum = 0;
        int res = INT_MAX;
        for (int j = 0; j < n; j ++ ) {
            sum += nums[j];
            while (sum >= target) {
                res = min(res, j - i + 1);
                sum -= nums[i++];
            }
        }
        if (res == INT_MAX) return 0;
        return res;
    }
};

int main() {
    unordered_map<int, int> mp;
    // mp['c'] = 1;
    cout << mp.size();
    return 0;
}