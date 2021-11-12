#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        vector<int> res;
        for (auto i : st1) {
            if (st2.count(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    unordered_map<int, int> mp;
    mp[0] = 1;
    cout << mp.count(0);

    return 0;
}